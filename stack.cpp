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
		if (currentSize==arraySize) cout<<"array is full"<<endl;
		else{
			currentSize++; 
			for(int i=currentSize-1;i>=currentLocation;i--){dataArray[i+1]=dataArray[i];}
			dataArray[currentLocation]=data;
	}
}
	void append(const E& data){
		if (currentSize==arraySize) cout<<"array is full"<<endl;
		else {currentSize++; dataArray[currentSize-1]=data;}
}
	E remove() {
		E a;
		int i;
		for(i =0 ; i<currentSize ; i++){}
		a = dataArray[i];
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





template<typename E> class stack{
void operator = (const stack&){}
stack(const stack&) {}
public:
	stack(){}
	virtual ~stack(){}
	virtual int length() const =0;
	virtual void push(const E& element) = 0;
	virtual E pop() = 0;
	virtual const E& currentElement() const = 0;
	virtual void clearStack() = 0;
	
};

template<typename E> class stackArrayList : public stack<E>{
	int stackSize;
	int currentLocation;//location pointer keeping track of cuurent element
	arrayList<E>* stackArray;//array for storing data
public:
	stackArrayList(int size){
		stackSize = size;
		stackArray = new arrayList<E>(size);
		currentLocation = 0;
	}
	~stackArrayList(){
		delete stackArray;
	}
	int length() const {
		return currentLocation;
	}
	void push(const E& element){
		if (currentLocation == stackSize) {cout<<"stack is full"<<endl; }
		else {stackArray->append(element);
		currentLocation++;}
	}
	E pop(){
		if(currentLocation==0){cout<<"stack is empty"<<endl; return 0;}
		return stackArray->remove();
	}
	const E& currentElement() const {
		//if(currentLocation == 0) {cout<<"stack is empty"<<endl; return 0;}
		return stackArray->getData();
	}
	void clearStack(){
		
		currentLocation = 0;
		stackSize = 0;
		stackArray->clear();
	}	
	void Display(){
		int i;
		stackArray->display();
	}
	
};

int main(){
	stackArrayList<int> s(10);
	while(1){
		cout<<"Press 0 to exit"<<endl;
		cout<<"Press 1 to get length of list"<<endl;
		cout<<"Press 3 to display elements"<<endl;
		cout<<"Press 2 to push an element into the stack"<<endl;
		cout<<"Press 4 to pop the last element"<<endl;
		cout<<"Press 5 to get current element"<<endl;
		cout<<"Press 6 to clear stack"<<endl;
		int i;
		cin>>i;
		switch(i){
			case 0 : return 0;
				break;
			case 1 : cout<<s.length()<<endl;
				break;
			case 2 : cout<<"Enter Element = ";
				cin>>i;
				s.push(i);
				break;
			case 3 :s.Display();
				break;
			case 4 : cout<<s.pop()<<endl;
				break;
			case 5 : cout<<s.currentElement()<<endl;
				break;
			case 6 : s.clearStack();
				break;
		}
	}
return 0;
}
