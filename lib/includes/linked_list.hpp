#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <cstdint>

namespace lib
{
    template <typename T>
    class DLinkedList
    {
    public:
        struct Node
        {
            T m_data{};
            Node *m_next{nullptr};
            Node *m_prev{nullptr};
            Node(const T &value) : m_data(value) {}
        };

    private:
        int32_t m_size{0};
        bool InsertEmptyList(const T &value)
        {
            auto new_node = new Node{value};
            m_head = new_node;
            m_tail = new_node;
            m_size++;
            return true;
        }
        bool InsertAtHead(const T &value)
        {
            if (m_head == nullptr)
            {
                return InsertEmptyList(value);
            }
            else
            {
                auto new_node = new Node{value};
                new_node->m_next = m_head;
                m_head->m_prev = new_node;
                m_head = new_node;
                m_size++;
                return true;
            }
            return false;
        }
        bool InsertAtTail(const T &value)
        {
            Node *new_node = new Node{value};
            m_tail->m_next = new_node;
            new_node->m_prev = m_tail;
            m_tail = new_node;
            m_size++;
            return true;
        }

        bool InsertInBetween(Node *left, const T &value)
        {
            Node *new_node = new Node{value};
            left->m_next->m_prev = new_node;
            new_node->m_next = left->m_next;
            new_node->m_prev = left;
            left->m_next = new_node;
            m_size++;
            return true;
        }

    public:
        typedef T value_type;
        Node *m_head{nullptr};
        Node *m_tail{nullptr};
        DLinkedList() {}
        int32_t Size() const { return m_size; }
        ~DLinkedList()
        {
            while (m_head != nullptr)
            {
                auto temp = m_head->m_next;
                m_head->m_prev = nullptr;
                delete m_head;
                m_head = temp;
            }
            m_tail = nullptr;
        }
        bool Insert(const int32_t pos, const T &value);
        T &front() { return m_head->m_data; }
        const T &front() const { return m_head->m_data; }
        T &back() { return m_tail->m_data; }
        const T &back() const { return m_tail->m_data; }
        const T &operator[](int position) const
        {
            int i = 0;
            const Node *target = m_head;
            while (i != position)
            {
                target = target->m_next;
                i++;
            }
            return target->m_data;
        }
        bool IsEmpty() const { return m_head == nullptr; }
        bool SortedInsertion(const T &value);
    };

    template <typename T>
    bool DLinkedList<T>::Insert(const int32_t pos, const T &value)
    {
        if (pos == 0)
        {
            return InsertEmptyList(value);
        }
        else if (pos == m_size)
        {
            return InsertAtTail(value);
        }
        else
        {
            auto i = 0;
            auto target_node = m_head;
            while (i != pos)
            {
                target_node = m_head->m_next;
                i++;
            }
            InsertInBetween(target_node, value);
        }
        return true;
    }

    template <typename T>
    bool DLinkedList<T>::SortedInsertion(const T &value)
    {
        Node *m_head_copy = m_head;
        if (IsEmpty())
        {
            return InsertAtHead(value);
        }
        else if (m_head_copy->m_data > value)
        {
            InsertAtHead(value);
        }
        else if (m_tail->m_data <= value)
        {
            InsertAtTail(value);
        }
        else
        {
            while (not(m_head_copy->m_data <= value and m_head_copy->m_next->m_data > value))
            {
                m_head_copy = m_head_copy->m_next;
            }
            InsertInBetween(m_head_copy, value);
        }
        return true;
    }

    template <typename T>
    class SLinkedList
    {
    private:
        void InsertAtHead(const T &value)
        {
            Node *new_node = new Node{value};
            m_head = new_node;
        }

        void DeleteAtHead()
        {
            auto temp = m_head->m_next;
            delete m_head;
            m_head = temp;
            temp = nullptr;
        }

    public:
        struct Node
        {
            T m_data{};
            Node *m_next{nullptr};
        };
        typedef T value_type;
        Node *m_head = nullptr;
        SLinkedList() {}
        ~SLinkedList()
        {
            while (m_head != nullptr)
            {
                auto temp = m_head->m_next;
                delete m_head;
                m_head = temp;
                temp = nullptr;
            }
        }
        void Append(const T &value)
        {
            if (m_head == nullptr)
            {
                InsertAtHead(value);
            }
            else
            {

                Node *temp = m_head;

                while (temp->m_next != nullptr)
                {
                    temp = temp->m_next;
                }

                Node *new_node = new Node{value};
                temp->m_next = new_node;
            }
        }
        T operator[](int index)
        {
            const Node *node_at_index = GetNodeAtIndex(index);
            return node_at_index->m_data;
        }
        Node *GetNodeAtIndex(const int index)
        {
            int i = 0;
            Node *head_copy = m_head;
            while (i != index and head_copy != nullptr)
            {
                head_copy = head_copy->m_next;
                i++;
            }
            return head_copy;
        }

        void Delete(Node *node_to_delete)
        {
            if (m_head != nullptr)
            {
                if (node_to_delete == m_head)
                {
                    DeleteAtHead();
                }
                else
                {
                    Node *temp = m_head;
                    while (temp->m_next == node_to_delete)
                    {
                        temp->m_next = node_to_delete->m_next;
                        delete node_to_delete;
                    }
                }
            }
        }
        void DeleteAtIndex(const int index)
        {
            if (m_head != nullptr)
            {
                if (index == 0)
                {
                    DeleteAtHead();
                }

                Node *delete_node = GetNodeAtIndex(index);
                if (delete_node != nullptr)
                {
                    Delete(delete_node);
                }
            }
        }
    };

    template <typename T>
    struct LinkedListNode
    {
        typedef T::Node *type;
    };

    template <typename T>
    void ReverseList(T &slinked_list)
    {

        auto head = slinked_list.m_head;

        if ((head != nullptr and head->m_next == nullptr) or head == nullptr)
        {
            return;
        }
        typename T::Node *new_head = nullptr;

        while (head != nullptr)
        {
            auto new_node = new T::Node{head->m_data};
            new_node->m_next = new_head;
            new_head = new_node;
            auto head_copy = head;
            head = head->m_next;
            delete head_copy;
            head_copy = nullptr;
        }
        slinked_list.m_head = new_head;
    }

    template <typename T>
    void ReverseLinkedListOptimizedIterative(T &slinked_list)
    {
        typename T::Node *prev = nullptr;
        auto current = slinked_list.m_head;
        auto next = current->m_next;
        while (current != nullptr)
        {
            next = current->m_next;
            current->m_next = prev;
            prev = current;
            current = next;
        }
        slinked_list.m_head = prev;
    }

    template <typename T>
    typename T::value_type Find_nth_ElementFromEnd(const T &slinked_list, const int n)
    {
        typename T::Node *fast = slinked_list.m_head;
        typename T::Node *slow = slinked_list.m_head;

        for (int i = 0; i < n; i++)
        {
            fast = fast->m_next;
        }
        while (fast != nullptr)
        {
            fast = fast->m_next;
            slow = slow->m_next;
        }
        return slow->m_data;
    }

    template<typename T>
    typename T::value_type GetMiddleElement(const T& slinked_list){

        typename T::Node *fast = slinked_list.m_head;
        typename T::Node *slow = slinked_list.m_head;
        while (fast != nullptr and fast->m_next!= nullptr )
        {
            fast = fast->m_next->m_next;
            slow = slow->m_next;
        }
        return slow->m_data;
    }

} // namespace lib

#endif