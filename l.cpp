
#include<iostream>
using namespace std;
template <typename E> class List{
	void operator = (const List&){}
	List (const List&);
public:
	List(){};
	virtual ~List(){};
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

template <typename E> class node {
public:
        E data;
        node *nextElement;
        node(const E& dataValue, node *nextElementPointer = NULL): data(dataValue), nextElement(nextElementPointer){};
};




template <typename E> class linkList : public List<E>{
	node<E>* firstElement;
	node<E>* lastElement;
	node<E>* currentElement;
	int sizeOfList;

public:
	linkList(){
		firstElement = lastElement = currentElement = new node<E>(0);
		sizeOfList = 0;
	};
	~linkList(){
		for(currentElement = firstElement; firstElement != NULL; firstElement = firstElement->nextElement){
			delete currentElement;
		}
	};
	int numberOfElements() const{return sizeOfList;}

	int CurrentLocation() const{
		int count = 1;
		node<E>* temp;
		for (temp = firstElement; temp!=currentElement; temp=temp->nextElement){count++;}
		return count;
 	}

	const E& getData() const{return currentElement->data;}

	void clear(){
		for(currentElement = firstElement; currentElement!=NULL; currentElement = currentElement->nextElement){delete currentElement; }
	sizeOfList = 0;
		firstElement = lastElement = currentElement = NULL;
	}





	void insert(const E& data){
		node<E>* temp = new node<E>(data);		
		if(sizeOfList == 0){
			firstElement=lastElement=currentElement=temp;}
		else if(firstElement==currentElement){
			temp->nextElement = firstElement;
			firstElement =  temp;
			currentElement = temp;}
		else if(lastElement == currentElement){
			lastElement->nextElement = temp;
			lastElement = lastElement->nextElement;
			currentElement = lastElement;}
		else{
			node<E>* temp2;
			for(temp2=firstElement; temp2->nextElement != currentElement; temp2= temp2->nextElement){}
			temp2->nextElement = temp;
			temp->nextElement = currentElement;}

		sizeOfList++;
	}



	void append(const E& data){
		node<E>* temp = new node<E>(data);
		if(sizeOfList == 0){
			firstElement = lastElement = currentElement = temp;}
		else{
			lastElement->nextElement = temp;
			lastElement = temp;
			currentElement = temp;}
		sizeOfList++;
	}

	E remove(){
		node<E>* temp = firstElement;
		if(currentElement == firstElement){
			firstElement = currentElement->nextElement;}
		else if(currentElement == lastElement){
			for(temp = firstElement; temp->nextElement != currentElement; temp = temp->nextElement){}
			temp->nextElement = NULL;
			lastElement = temp;}
		else{
			for(temp = firstElement; temp->nextElement != currentElement; temp = temp->nextElement){}
			temp->nextElement = currentElement->nextElement;}
		sizeOfList--;
	}
	
	void setListLocationToStart(){
		currentElement = firstElement;
	}
	void setListLocationToEnd(){
		currentElement = lastElement;
	}

	void nextElement(){
		if(currentElement == lastElement){cout<<"Invalid location"<<endl;}
		else {currentElement = currentElement->nextElement;}
	}
	void previousElement(){
		node<E>* temp;
		for(temp = firstElement; temp->nextElement != currentElement; temp = temp->nextElement){}
		currentElement = temp;
	}

	int setToNewLocation(int location){
		if(location>sizeOfList) {cout<<"invalid location"<<endl; return -1;}
		currentElement = firstElement;
		for(int i = location-1; i>0; i--){
			currentElement = currentElement->nextElement;
		}
		return location;
	}

	void display(){
		node<E>* temp;
		for(temp = firstElement; temp!= NULL; temp = temp->nextElement){
			cout << temp->data << endl;}
	}
};



int main(){

	linkList<int> l;
	l.append(10);l.append(11); 
	cout<<"Displaying Elements"<<endl;
	l.display();      
	cout<<"current Data "<<l.getData()<<endl;
	l.insert(5); l.insert(6);
	cout<<"Displaying Elements"<<endl;
	l.display();
  	cout<<endl;
	
        cout<<"Data "<<l.getData()<<endl;	
	cout<<"Current Location"<< l.CurrentLocation()<<endl;
	l.insert(13);
	cout<<"Displaying Elements"<<endl;
	l.display();
	cout<<"current Data "<<l.getData()<<endl;
	cout<<"Current Location"<< l.CurrentLocation()<<endl;

	cout<<endl;


	cout<<"going to next element"<<endl;
	l.nextElement();                 //setting current element pointer to next element pointer
	
	cout<<"setting current to new location"<<l.setToNewLocation(2)<<endl;
	cout<<"current Data "<<l.getData()<<endl;

	cout<<"going to next element"<<endl;
	l.nextElement(); 
	cout<<"current Data "<<l.getData()<<endl;

	cout<<"Number of Elements "<<l.numberOfElements()<<endl;

	cout<<"removing current element "<<endl;
	l.remove();
	cout<<"Displaying Elements"<<endl;
	l.display();
	cout<<"Number of Elements "<<l.numberOfElements()<<endl;

	cout<<endl;
	cout<<"setting list location to start"<<endl;
	l.setListLocationToStart();
	cout<<"current Data "<<l.getData()<<endl;

	cout<<endl;
	cout<<"setting list location to end"<<endl;
	l.setListLocationToEnd();
	cout<<"current Data "<<l.getData()<<endl;

	l.previousElement();
	cout<<"setting location to previous element"<<endl;
	cout<<"current Data "<<l.getData()<<endl;

	cout<<endl;

	l.clear();
	cout<<"clearing list"<<endl;
	cout<<"Number of Elements "<<l.numberOfElements()<<endl;
	
	while(1){
		int i;
		
		cout<<"press 0 to exit"<<endl;
		cout<<"Press 1 to insert"<<endl;
		cout<<"Press 2 to append"<<endl;
		cout<<"Press 3 to display elements"<<endl;
		cout<<"Press 4 to get number of elements"<<endl;
		cout<<"Press 5 to get current element"<<endl;
		cout<<"Press 6 to get currentLocation"<<endl;
		cout<<"Press 7 to remove current element"<<endl;
		cout<<"Press 8 to go to next element"<<endl;
		cout<<"Press 9 to go to previous element"<<endl;
		cout<<"Press 10 to go to first element"<<endl;
		cout<<"Press 11 to go to last element"<<endl;
		cout<<"Press 12 to set new current location"<<endl;
		cout<<"Press 13 to clear array list"<<endl;
		cin>>i;
		if(i==0) return 0;
		
		switch (i){
			case 1: cout<<"Input element = ";
				cin>>i;
				l.insert(i);
				break;
			case 2: cout<<"Input element = ";
				cin>>i;
				l.append(i);
				break;
			case 3: l.display();
				break;
			case 4: cout<<l.numberOfElements()<<endl;
				break;
			case 5: cout<<l.getData()<<endl;
				break;
			case 6: cout<<l.CurrentLocation()<<endl;
				break;
			case 7: l.remove();
				break;
			case 8: l.nextElement();
				break;
			case 9: l.previousElement();
				break;
			case 10: l.setListLocationToStart();
				break;
			case 11: l.setListLocationToEnd();
				break;
			case 12: cout<<"Enter Location = ";
				cin>>i;
				i=l.setToNewLocation(i);
				break;
			case 13: l.clear();
	}
}	
return 0;
}
