//#include <iostream>
//#include <list>
//using namespace std;
//
//// Forward declaration
//class Observer;
//
//// The Observer pattern is used to create a subscription mechanism where multiple objects (observers) 
//// are listening to and reacting to events or changes in another object 
//// (the subject or model). When the subject changes its state, it automatically notifies all its observers.
//
//// Model; reprents the subject in the Observer Pattern.
//class Model {
//
//    int value; // some value of data.
//    list<Observer*> observers; // A list of observers that are interested in changes to the model.
//
//public:
//
//    void attach(Observer* obs) //  Adds an observer to the list
//    {
//        observers.push_back(obs);
//    }
//
//    void setVal(int val) // Sets the model's value and calls notify() to inform all observers about the change.
//    {
//        value = val;
//        notify();
//    }
//
//    int getVal() const // Returns the current value.
//    {
//        return value;
//    }
//
//    void notify();
//};
//
//// Observer; an abstract class for observers watching the model. Each observer is associated with a model and a divisor.
//class Observer {
//
//    Model& model;
//    int denom;
//
//public:
//    Observer(Model& mod, int div) : model(mod), denom(div) 
//    {
//        model.attach(this); // Constructor that attaches the observer to a model.
//    }
//
//    virtual void update() = 0;
//
//protected:
//    Model& getModel() const 
//    {
//        return model;
//    }
//
//    int getDivisor() const 
//    {
//        return denom;
//    }
//};
//
//void Model::notify() {
//    for (Observer* obs : observers) 
//    {
//        obs->update();
//    }
//}
//
//// Concrete Observers
//class DivObserver : public Observer {
//public:
//    DivObserver(Model& mod, int div) : Observer(mod, div) {}
//
//    void update() override 
//    {
//        int v = getModel().getVal(), d = getDivisor();
//        cout << v << " div " << d << " is " << v / d << '\n';
//    }
//};
//
//class ModObserver : public Observer {
//public:
//    ModObserver(Model& mod, int div) : Observer(mod, div) {}
//
//    void update() override 
//    {
//        int v = getModel().getVal(), d = getDivisor();
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