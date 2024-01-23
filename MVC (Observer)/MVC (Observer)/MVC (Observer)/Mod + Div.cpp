//#include <iostream>
//#include <list>
//using namespace std;
//
//// forward declaration
//class observer;

//// the observer pattern is used to create a subscription mechanism where multiple objects (observers) 
//// are listening to and reacting to events or changes in another object 
//// (the subject or model). when the subject changes its state, it automatically notifies all its observers.
//
//// model; reprents the subject in the observer pattern.
//class model {
//
//    int value; // some value of data.
//    list<observer*> observers; // a list of observers that are interested in changes to the model.

//public:
//
//    void attach(observer* obs) //  adds an observer to the list
//    {
//        observers.push_back(obs);
//    }
//
//    void setval(int val) // sets the model's value and calls notify() to inform all observers about the change.
//    {
//        value = val;
//        notify();
//    }
//
//    int getval() const // returns the current value.
//    {
//        return value;
//    }
//
//    void notify();
//};
//
//// observer; an abstract class for observers watching the model. each observer is associated with a model and a divisor.
//class observer {
//
//    model& model;
//    int denom;
//
//public:
//    observer(model& mod, int div) : model(mod), denom(div) 
//    {
//        model.attach(this); // constructor that attaches the observer to a model.
//    }
//
//    virtual void update() = 0;
//
//protected:
//    model& getmodel() const 
//    {
//        return model;
//    }
//
//    int getdivisor() const 
//    {
//        return denom;
//    }
//};
//
//void model::notify() {
//    for (observer* obs : observers) 
//    {
//        obs->update();
//    }
//}
//
//// concrete observers
//class divobserver : public observer {
//public:
//    divobserver(model& mod, int div) : observer(mod, div) {}
//
//    void update() override 
//    {
//        int v = getmodel().getval(), d = getdivisor();
//        cout << v << " div " << d << " is " << v / d << '\n';
//    }
//};
//
//class modobserver : public observer {
//public:
//    modobserver(model& mod, int div) : observer(mod, div) {}
//
//    void update() override 
//    {
//        int v = getmodel().getval(), d = getdivisor();
//        cout << v << " mod " << d << " is " << v % d << '\n';
//    }
//};
//
////main function
//int main() {
//    model m;
//    divobserver divobs1(m, 4);
//    divobserver divobs2(m, 3);
//    modobserver modobs3(m, 3);
//
//    m.setval(14);
//    return 0;
//}