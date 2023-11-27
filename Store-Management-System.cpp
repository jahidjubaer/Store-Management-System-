#include <bits/stdc++.h>

using namespace std;

class temp {

    string itemID, itemName ;
    int itemQuantity, itemPrice ;
    fstream file , file1 ;
    int totalAmount, quantity, itemRate;
    string search;
    char _choice;


public:

    void addProduct(void) ;
    void viewProduct(void) ;
    void buyProduct(void) ;


}obj ;

int main() {
    char choice;

    cout << "------Well Come to Jahid's Varieties Store-----" << endl << endl ;
    cout << "Press 1 --> Start shopping" << endl;
    cout << "Press 0 --> Exit" << endl << endl;
    cin >> choice;


        if(choice == 'A') {

             obj.addProduct();
            obj.viewProduct();


        }

        else if(choice == '1' ){
            obj.viewProduct();
            obj.buyProduct();
        }

        else if(choice == '0') {
            return 0 ;

        }
        else {
           cout << "You pressed a wrong key." << endl;
        }



    return 0;
}

void temp::addProduct() {


    _choice = 'y' ;
    string add ;

    cout << "To add New Product --- > Press 'a' " << endl ;
    cout << "To Start Shoping ---- > Press 's' " << endl ;
    cout << "TO see Product list -- > Press 'l' " << endl ;
    cout <<  "To exit ---- > Press 'e' " << endl ;

    cin >> add ;

    if (add == "a") {

    while ( _choice == 'y' ) {

        cout <<  "Enter Product ID :: " ;

         cin  >> itemID;

         cout << "Enter Product Name :: " ;
        cin >> itemName ;


        cout << "Enter Product Quantity :: " ;
          cin >> itemQuantity;
        cout << "Enter Product Price :: " ;
        cin >>  itemPrice ;

        file.open("data.txt", ios::out | ios::app );
        file << itemID << "\t" << itemName << "\t" << itemQuantity << "\t" << itemPrice << endl;
        file.close() ;

        cout << "Product added successfully!" << endl ;

        cout << "Do you want to add another product? (y/n): " ;

        cin >> _choice;

        cout << endl ;
    }
    }

    else if (add == "l") {
        obj.viewProduct() ;
    }

    else if(add == "b" ) {
        obj.viewProduct();
            obj.buyProduct();
    }
    else if (add == "c") {
        return ;
    }
    else {
        cout << "You enter wrong Exit !!!!" << endl ;
        return ;
    }
}

void temp::viewProduct() {
    file.open("data.txt", ios::in);

    if (!file.is_open()) {
        cout << "Error opening the file. Exiting..." << endl;

        return;
    }


    bool noProducts = true ;
    while (file >> itemID >> itemName >> itemQuantity >> itemPrice) {
        noProducts = false ;
        cout << "______________________________________________________________________________________________" << endl;
        cout << "Product ID\t   Product Name\t\t    Quantity   \t\tProduct Price" << endl ;
        cout << itemID << "\t\t\t" << itemName << "\t\t\t" << itemQuantity << "\t\t\t" << itemPrice << endl;
        cout << "______________________________________________________________________________________________" << endl ;
        cout << endl ;
    }

    file.close();

    if (noProducts)
        {
        cout << "No products in stock." << endl;
    }
}


void temp::buyProduct() {
    _choice = 'y';

    while (_choice == 'y') {

        file.open("data.txt", ios::in);
        file1.open("temp.txt", ios::out | ios::app);

        cout << "Enter Product Id :: ";
        cin >> search;
        cout << "Enter Quantity: ";
        cin >> quantity;
            bool found = false;
        bool outOfStock = false;

        while (file >> itemID >> itemName >> itemQuantity >> itemPrice) {
            if (itemID == search ) {
                found = true;

                if (quantity > itemQuantity ) {
                    outOfStock = true;
                } else {
                    itemQuantity -= quantity;
                    file1 << itemID << "\t" << itemName << "\t" << itemQuantity << "\t" << itemPrice << endl;

                    itemRate = quantity * itemPrice;
                    totalAmount += itemRate;

                    cout << "---------Payment Bill----------" << endl;
                    cout << "Total Purchase Amount :: " << totalAmount << endl;
                    cout << "________________________________" << endl;
                }
            } else {
                file1 << itemID << "\t" << itemName << "\t" << itemQuantity << "\t" << itemPrice << endl;
            }
        }

        file.close();
        file1.close();
        remove("data.txt");
        rename("temp.txt", "data.txt");

        if (!found)
        {
        cout << "Item ID is wrong. Please enter a valid Item ID." << endl;
        } else if (outOfStock)

        {
            cout << endl ;
            cout << "Out of quantity limit. Please enter a quantity within the available stock." << endl;

        }


        cout << "\nContinue Shopping? (y / n): ";
        cout << endl ;
        cin >> _choice;
    }
}






