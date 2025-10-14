#include<iostream>
using namespace std;

int main(){
    int rows, cols;
    cout<<"Enter number of rows: "<<endl;
    cin>>rows;
    cout<<"Enter number of cols: "<<endl;
    cin>>cols;

    int **matrix;
    
    matrix = new int*[rows];
    for(int i = 0;i<rows;i++){
        matrix[i] = new int[cols];
    }

     cout<<"Enter elements"<<endl;
     for(int i = 0; i<rows;i++){
        for(int j = 0; j < cols; j++){
            cout<<"Elements "<<i<<" "<<j<<endl;
            cin>>matrix[i][j];
        }
     }

     cout<<"Display"<<endl;
     for(int i = 0;i<rows;i++){
        for(int j = 0; j<cols;j++){
            cout<<matrix[i][j]<<endl;;
        }
        cout<<endl;
     }

     for(int i = 0;i<rows;i++){
        delete [] matrix[i];
     }
     delete[]matrix;
    return 0;
}