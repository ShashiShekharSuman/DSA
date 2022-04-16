#include <iostream>
#include <utility>

using namespace std;

int const max_size = 100;

class SparseMatrix{

    float **sparse_matrix;
    int rows, columns;
    int number_of_elements;

    public:

    SparseMatrix(int row, int column){
        this->rows = rows;
        this->columns = columns;
        this->number_of_elements = 0;
        this->sparse_matrix = new float *[max_size];
        for (int i=0; i < max_size; i++){
            sparse_matrix[i] = new float[3];
        }
    }

    void insert(int, int, float);
    void transpose();
    void display();
};

void SparseMatrix::insert(int row, int column, float data){
    sparse_matrix[number_of_elements][0] = row;
    sparse_matrix[number_of_elements][1] = column;
    sparse_matrix[number_of_elements][2] = data;
    number_of_elements++;
}

void SparseMatrix::transpose(){
    int row_index = 0;
    for (int column_index=0; column_index < columns; column_index++) 
        for (int i=row_index; i < number_of_elements; i++){
            if (sparse_matrix[i][1] == column_index){
                swap(sparse_matrix[i][0], sparse_matrix[i][1]);
                // if (i == 0) break;
                swap(sparse_matrix[i], sparse_matrix[row_index++]);
            }
        }
}

void SparseMatrix::display(){
    cout << "Row\tCoulumn\t\tValue" << endl;
    for(int i=0; i < number_of_elements; i++){
        cout << sparse_matrix[i][0] << "\t"
             << sparse_matrix[i][1] << "\t\t"
             << sparse_matrix[i][2] << endl;
    }
    cout << endl;
}

int main(){
    SparseMatrix sp(5, 5);
    sp.insert(0, 3, 5);
    sp.insert(1, 4, 7);
    sp.insert(2, 0, 2.5);
    sp.insert(3, 1, 3);
    sp.insert(4, 2, 7.9);
    cout<<"Sparce Matrix:"<<endl;
    sp.display();
    sp.transpose();
    cout<<"Transpose of Sparce Matrix:"<<endl;
    sp.display();
    return 0;
}