#include <iostream>
#include <string>
using namespace std;
int main() {
    int Set_price[6] = {0, 4, 8, 7, 6, 3};
    string Set_name[6] = {"XXXXXXXXXXXXX"
                        , "Medium Wac"
                        , "WChicken Nugget"
                        , "Geez Burger"
                        , "ButtMilk Crispy Chicken"
                        , "Plastic Toy"};
    int Dish_price[5] = {0, 2, 3, 5, 7};
    string Dish_name[5] = {"XXXXXXXXXXXX"
                        , "German Fries"
                        , "Durian Slices"
                        , "WcFurry"
                        , "Chocolate Sunday"};
    int temp = 3, total = 0;
    while (1) {
        cin >> temp;
        if (temp == 1) {
            cin >> temp;
            cout << Set_name[temp] << " " << Set_price[temp] << endl;
            total += Set_price[temp];
        }
        else if (temp == 2) {
            cin >> temp;
            cout << Dish_name[temp] << " " << Dish_price[temp] << endl;
            total += Dish_price[temp];
        }
        else {
            printf("Total: %d\n", total);
            break;
        }
    }
    return 0;
}

