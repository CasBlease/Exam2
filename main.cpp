#include <iostream>
#include <vector>
using namespace std;


class Item{
  public:
    Item();
    Item(string uName, double uCost);
    void Print();
  //private:
    string name;
    double cost;
};

//Default constructor
Item::Item(){
  name = "pencil";
  cost = 2.3;
}

//User constructor
Item::Item(string uName, double uCost){
  name = uName;
  cost = uCost;
}

//prints out item name and cost
void Item::Print(){
  cout << "Item " << name << " Costs " << cost << endl;
}

double compute_item_cost(Item obj, int n){
  double compCost = obj.cost * n;

  cout << n << " " << obj.name << " costs " << to_string(compCost) << endl;
  
  return compCost;
}

void display_cart_total(vector<Item> uCart){
  double total;
  for(int i=0; i<uCart.size(); i++){
    total += uCart[i].cost;
    //for some reason when the following line isn't there cout << total prints "$nan"
    cout << total << endl;
  }

  total*=1.1;
  
  cout << "Your cart costs : $" 
    << total << " for " 
    << uCart.size() 
    << " items (10% tax included)" << endl;
}

int main()
{
    srand(time(NULL));
    vector<Item> cart;
    string name;
    double cost;

    cout << "Enter an item name and cost: ";
    cin >> name >> cost;

    Item i1{name, cost};
    Item i2{"mouse", 13.5};
    Item i3{"toothbrush", 0.43};

    i1.Print();

    int rand_amt = (rand() % 10);
    compute_item_cost(i1, rand_amt);
    compute_item_cost(i2, rand_amt);

    cout << "Making a cart" << endl;
    cart.push_back(i1);
    cart.push_back(i2);
    cart.push_back(i3);
    display_cart_total(cart);
    return 0;

}
