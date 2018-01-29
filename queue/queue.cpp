#include <iostream>
using namespace std;

class Queue{
  private:
    int front, rear, size, queueSize;
    int* arr;

    bool isFull(){
      if (queueSize==size)return true;
      else return false;
    }

    bool isEmpty(){
      if (queueSize==0)return true;
      else return false;
    }

  public:
    Queue(int s){
      front=-1;
      rear=0;
      queueSize=0;
      size = s;
      arr = new int[size]();
    }

    void enqueue(int x){
      if (isFull()){
        cout<<"Overflow\n";
        return;
      }
      front=(front+1)%size;
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
      rear=(rear+1)%size;
      queueSize--;
      return result;
    }

    int Front(){
      return arr[front];
    }

    int Rear(){
      return arr[rear];
    }

};


int main(){
  Queue Q(10);
  int elem=0;
  while(1){
    cin>>elem;
    if(elem==-1) break;
    else if (elem==-2) {
      cout<<Q.dequeue()<<endl;
    }
    else Q.enqueue(elem);
  }

}
