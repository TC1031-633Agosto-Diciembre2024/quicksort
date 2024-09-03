#include <iostream>
#include <vector>

using namespace std;

void swap(int* a, int* b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(vector<int>& vec,int start, int end) {
    int pivot=vec[end];
    int i=start-1;
    for(int j=start;j<end;j++) {
        if(vec[j]<pivot) {
            i++;
            swap(&vec[i],&vec[j]);
        }
    }
    swap(&vec[i+1],&vec[end]);
    return i+1;
}

void quicksort(vector<int>& vec,int start, int end) {
    if(start<end) {
        int pivot=partition(vec,start,end);
        quicksort(vec,start,pivot-1);
        quicksort(vec,pivot+1,end);
    }
}

void printVector(vector<int>& vec) {
    int size=vec.size();
    cout<<"[";
    for(int i=0;i<size;i++) {
        cout<<vec[i]<<",";
    }
    cout<<"]"<<endl;

}

int main() {
    vector<int> vec={5,2,3,1,8,4,7,6};
    printVector(vec);
    quicksort(vec,0,vec.size()-1);
    printVector(vec);
    return 0;
}
