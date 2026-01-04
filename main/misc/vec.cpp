#include <cstdint>
#include<iostream>
#include<vector>
#include<cstdlib>



int32_t SmallestEqualIndex(const std::vector<int32_t>& data){
    size_t max_size = data.size();
    for (size_t i = 0; i <max_size ; i++)
    {
        if ((data[i]%10) == (i%10))
        {
            return i;
        }
        
    }
    return -1;
    
}

using vector_2d = std::vector<std::vector<std::int32_t>>;

int32_t MatrixDiagonalSum(const vector_2d& matrix){
    const size_t n_row = matrix.size()-1;
    const size_t n_col = matrix.front().size()-1;
    int32_t sum = 0;
    for (size_t i = 0; i <= n_row; i++)
    {
        const auto right_diagonal =  (i == (n_col-i))?0:matrix[i][n_col-1];
        sum += matrix[i][i]  + right_diagonal;
    }
    
    return sum;

}

bool IsToeplitz(const vector_2d& matrix){

}




int main(){
    std::vector<int>v ={103,12321,38973};
    std::cout<< SmallestEqualIndex(v)<<std::endl;
    vector_2d matrix (3,{1,1,1});
    std::cout << MatrixDiagonalSum(matrix) <<std::endl;
}