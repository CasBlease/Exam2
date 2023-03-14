#include <iostream>
#include <vector>
using namespace std;

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
