#include <iostream>
using namespace std;

class queue{
  private:
    int front=-1;
    int rear=-1;
    int queueSize=0;
    int size=0;
    int* arr;

    bool isFull(){
      if (queueSize==size)return true;
      else false;
    }

    bool isEmpty(){
      if (queueSize==0)return true;
      else false;
    }

  public:
    queue(int s){
      size = s;
      arr = new int[size]();
    }

    void enqueue(int x){
      if (isFull()){
        cout<<"Overflow\n";
        return;
      }
      front=(front++)%size;
      queueSize++;
      arr[front]=x;
      return;
    }

    int dequeue(){
      if (isEmpty()){
        cout<<"Underflow\n";
        return -1;
      }
      int result = arr[rear];
      rear=(rear++)%size;
      queueSize--;
      return result;
    }

};


int main(){
  queue Q(10);
  int elem=0;
  while(1){
    cin>>elem;
    if(elem==-1) break;
    if (elem==-2) {
      cout<<Q.dequeue()<<endl;
    }
    Q.enqueue(elem);
  }

}
