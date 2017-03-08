#include<iostream>

using namespace std;

template <typename E> class List{
	void operator = (const List&);
	List (const List&){}
public:
	List(){}
	virtual ~List(){}
	virtual int numberOfElements() const =0;
	virtual int CurrentLocation() const=0;
	virtual const E& getData() const =0;
	virtual void clear()=0;
	virtual void insert (const E& data)=0;
	virtual void append(const E& data)=0;
	virtual E remove()=0;
	virtual void setListLocationToEnd()=0;
	virtual void setListLocationToStart()=0;
	virtual void nextElement()=0;
	virtual int setToNewLocation(int location)=0;
};


template<typename E> class arrayList : public List<E>{
	int arraySize;
	int currentLocation;
	int currentSize;
	E* dataArray;
public:
	arrayList(int size){
		arraySize = size;
		currentSize = currentLocation = 0;
		dataArray = new E[arraySize];
}
	~arrayList(){
		delete [] dataArray;
}
	int numberOfElements() const {
		return currentSize;
}
	int CurrentLocation() const {
		return currentLocation;
}
	const E& getData() const {
		return dataArray[currentLocation];
}
	void clear(){
		for(int i =0;i<currentSize;i++){dataArray[i]=0;}
		currentLocation = currentSize = 0;

}
	void insert(const E& data) {
		if (currentSize==arraySize) {cout<<"array is full"<<endl;}
		else{
			currentSize++; 
			for(int i=currentSize-1;i>=currentLocation;i--){dataArray[i+1]=dataArray[i];}
			dataArray[currentLocation]=data;
	}
}
	void append(const E& data){
		if (currentSize==arraySize) {cout<<"array is full"<<endl;}
		else {currentSize++; dataArray[currentSize-1]=data;}
}
	E remove() {
		E a = dataArray[currentLocation];
		int i;
		for(i = currentLocation ; i<currentSize ; i++){dataArray[i] = dataArray[i+1];}
		currentSize--;
		return a;
}
	void setListLocationToStart(){currentLocation=0;}

	void setListLocationToEnd(){currentLocation=currentSize-1;}

	void previousElement(){if (currentLocation==0) cout<<"Error"<<endl; else currentLocation--;}

	void nextElement(){if (currentLocation==currentSize-1) cout<<"Error"<<endl; else currentLocation++;}

	int setToNewLocation(int location){
		if(location>=1 && location<=currentSize){currentLocation=location-1;return location;}
		else { cout<<"Error"<<endl; return -1;}

}
	void display(){
		for (int i= 0;i<currentSize;i++){cout<<dataArray[i]<<endl;}
}
};






template<typename E> class Queue{
 void operator = (const Queue&){}
 Queue (const Queue&){}

public:
 Queue () {} //Constructor
 ~Queue () {} //Destructor

 virtual void Enqueue(const E&) = 0;//Insert element in queue
 virtual E Dequeue() = 0;//remove eleement
 virtual int length() const = 0;
 virtual const E& FirstElement() const = 0;//return a copy of first element
 virtual void clearQueue() = 0;
};

template <typename E> class queueArrayList : public Queue<E> {
 int maxSize;//maximum size of array
 int firstElement;// index of first element of queue
 int lastElement;// index of last element of queue
 arrayList<E>* queueArray;//array for storing data

public:
 //Constructor
 queueArrayList(int size){                   
	maxSize = size;
	queueArray = new arrayList<E>(size);
	firstElement = lastElement = 0;
	}
 //Destructor
 ~queueArrayList(){delete queueArray;}
 //Insert
 void 	Enqueue(const E& data){
	queueArray->append(data);
}

 E Dequeue(){
	queueArray->setListLocationToStart();
	return queueArray->remove();
}

 int length() const {
	return queueArray->numberOfElements();
}

 const E& FirstElement() const{
	queueArray->setListLocationToStart();
	return queueArray->getData();	
}

 void clearQueue(){
	queueArray->clear();
}

 void displayQueue(){
	queueArray->display();
}

};

int main(){
	int i;
	cout<<"Enter the length of Queue"<<endl;
	cin>>i;
	queueArrayList<int> q(i);

	while(1){
		cout<<"Press 0 to exit"<<endl;
		cout<<"Press 1 to enqueue"<<endl;
		cout<<"Press 2 to dequeue"<<endl;
		cout<<"Press 3 to get length of queue"<<endl;
		cout<<"Press 4 to get first element"<<endl;
		cout<<"Press 5 to clear queue"<<endl;
		cout<<"Press 6 to display"<<endl;
		cin>>i;
		if (i==0){return 0;}
		switch (i) {
			case 1 :cout<<"Enter element"<<endl;
				cin>>i;
				q.Enqueue(i);
				break;
			case 2 :cout<<q.Dequeue()<<endl;
				break;
			case 3 :cout<<q.length()<<endl;
				break;
			case 4 :cout<<q.FirstElement()<<endl;
				break;
			case 5 :q.clearQueue();
				break;
			case 6 :q.displayQueue();
				break;
		}
	}
return 0;
}
