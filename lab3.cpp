#include<iostream>
using namespace std;
template <typename E> class List{
	void operator = (const List&){}
	List (const List&);
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
		E a=dataArray[currentLocation];
		for (int i = currentLocation;i<currentSize-1;i++){dataArray[i]=dataArray[i+1];}
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

int main(){

	arrayList<int> a(10); 
	while(1){
		int i;
		
		cout<<"press 0 to exit"<<endl;
		cout<<"Press 1 to insert"<<endl;
		cout<<"Press 2 to append"<<endl;
		cout<<"Press 3 to display elements"<<endl;
		cout<<"Press 4 to get number of elements"<<endl;
		cout<<"Press 5 to get current element"<<endl;
		cout<<"Press 6 to remove current element"<<endl;
		cout<<"Press 7 to go to next element"<<endl;
		cout<<"Press 8 to go to previous element"<<endl;
		cout<<"Press 9 to go to first element"<<endl;
		cout<<"Press 10 to go to last element"<<endl;
		cout<<"Press 11 to set new current location"<<endl;
		cout<<"Press 12 to clear array list"<<endl;
		cin>>i;
		if(i==0) return 0;
		
		switch (i){
			case 1: cout<<"Input element = ";
				cin>>i;
				a.insert(i);
				break;
			case 2: cout<<"Input element = ";
				cin>>i;
				a.append(i);
				break;
			case 3: a.display();
				break;
			case 4: cout<<a.numberOfElements()<<endl;
				break;
			case 5: cout<<a.getData()<<endl;
				break;
			case 6: a.remove();
				break;
			case 7: a.nextElement();
				break;
			case 8: a.previousElement();
				break;
			case 9: a.setListLocationToStart();
				break;
			case 10: a.setListLocationToEnd();
				break;
			case 11: cout<<"Enter Location = ";
				cin>>i;
				a.setToNewLocation(i);
				break;
			case 12: a.clear();
	}
}
return 0;
}
