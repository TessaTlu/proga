#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
int sizeNum(int Num);
class element{
public:
    int value;
    element* next;
    element* prev;
    element(int x){
        value=x;
    }
};
class List{
public:
    int size;
    element first = element(0);
    element last = element(0);
    List(int N, std::vector <int> Input){
        element* previous;
        size = N;
        first.value = Input[0];
        last.value = Input[Input.size()-1];
        for (int i=N-1; i>0; i--){
            element *current = new element(Input[i]);
            if (i==1){
                previous->prev=current;
                current->next = previous;
                first.next = current;
            }
            else if(i<N-1){
                previous->prev=current;
                current->next = previous;
            }
            previous=current;
        }
    }
    void printList(){
        element* current = &first;
        for (int i=0; i<size; i++){
            int sizeCurrent = sizeNum(current->value);
            std::string format(5-sizeCurrent, ' ');
            std::cout<<current->value<<format;
            current = current->next;
        }
        std::cout<<"\n";
    }
    void printBackList(){
        element* current = &first;
        for (int i=size-1; i>0; i--){
            int sizeCurrent = sizeNum(current->value);
            std::string format(5-sizeCurrent, ' ');
            std::cout<<current->value<<format;
            current = current->next;
        }
        std::cout<<"\n";
    }
};


int main()
{
    int B;
    int n;
    std::cin>>B;
    std::vector <int> Mas;
    for (int i=0; i<B; i++){
        std::cin>>n;
        Mas.push_back(n);
    }
    List T = List(Mas.size(), Mas);
    std::cout<<T.first.next->next->prev->value;
}
int sizeNum(int Num){
    int k =0;
    while(Num!=0){
        Num=Num/10;
        k++;
    }
    return k;
}