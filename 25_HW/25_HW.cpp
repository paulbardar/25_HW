// 25_HW.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "Computer.h"


int main()
{
    
    Computer emptyPC;

    cout << "object data after default constructor:" << endl;
    emptyPC.showInfo();

    vector<Computer> inventory;
    inventory.push_back(Computer("MSI", 4.0, 32, false, 45000.0));
    inventory.push_back(Computer("Expert PC", 3.6, 16, false, 35999.0));
    inventory.push_back(Computer("Lenovo V15", 2.6, 12, true, 18000.0));
    inventory.push_back(Computer("Acer Aspire DVD", 2.8, 8, true, 14999.0));


    cout << "Added " << inventory.size() << " computers." << std::endl;

    for (const auto& pc : inventory) {
        pc.showInfo();
    }

    cout << "==============================================" << endl;
    cout << "================== 1 task ====================" << endl;

    // 1 task

    string searchName;
    cout << "Enter the computer name to search for: ";
    getline(cin, searchName);

    
    auto it = find_if(inventory.begin(), inventory.end(), [&searchName](const Computer& c) {
        return c.getName() == searchName;
        });

    
    if (it != inventory.end()) {
        cout << "\nItem found:" << endl;
        it->showInfo();

     
        cout << "\nChange price? Enter new one: ";
        double newPrice;
        cin >> newPrice;
        it->setPrice(newPrice);

        cout << "Updated data: ";
        it->showInfo();
    }
    else {
        cout << "\nComputer with name '" << searchName << "' not found." << endl;
    }


    cout << "==============================================" << endl;
    cout << "================== 2 task ====================" << endl;

    cout << "List to delete (number of: " << inventory.size() << "):" << endl;
    for (const auto& pc : inventory) pc.showInfo();

   
    if (!inventory.empty()) {
        auto minIt = min_element(inventory.begin(), inventory.end(),
            [](const Computer& a, const Computer& b) {
                return a.getFrequency() < b.getFrequency();
            });

        cout << "\nFound PC with the lowest frequency (" << minIt->getFrequency() << " GHz):" << endl;
        minIt->showInfo();

      
        inventory.erase(minIt);

        cout << "\nItem successfully deleted." << endl;
    }

    cout << "\nList to delete (number of: " << inventory.size() << "):" << endl;
    for (const auto& pc : inventory) pc.showInfo();


    cout << "==============================================" << endl;
    cout << "================== 3 task ====================" << endl;

    inventory.push_back(Computer("Acer Aspire DVD", 2.8, 8, true, 14999.0));
    for (const auto& pc : inventory) {
        pc.showInfo();
    }

    int dvdCount = count_if(inventory.begin(), inventory.end(), [](const Computer& c) {
        return c.getHasDVD();
        });

    cout << "Number of computers with DVD: " << dvdCount << endl;


    cout << "==============================================" << endl;
    cout << "================== 4 task ====================" << endl << endl;

    cout << "Prices before updates:" << endl;
    for (const auto& pc : inventory) pc.showInfo();

    
    std::for_each(inventory.begin(), inventory.end(), [](Computer& c) {
        if (c.getRamSize() > 16) {
            double oldPrice = c.getPrice();
            c.setPrice(oldPrice * 1.1); 
        }
        });

    cout << "\nPrices after update (for PCs with RAM > 16GB increased by 10%):" << endl;
    for (const auto& pc : inventory) pc.showInfo();


    cout << "==============================================" << endl;
    cout << "================== 5 task ====================" << endl << endl;

    inventory.push_back(Computer("Dell OptiPlex", 3.5, 32, true, 42000.0));

    // Sort by ASCENDING price
    sort(inventory.begin(), inventory.end(), [](const Computer& a, const Computer& b) {
        return a.getPrice() < b.getPrice(); 
        });

    cout << "--- Sort by ASCENDING price ---" << std::endl;
    for (const auto& pc : inventory) pc.showInfo();

    // Sort by DESCENDING price
    sort(inventory.begin(), inventory.end(), [](const Computer& a, const Computer& b) {
        return a.getPrice() > b.getPrice(); 
        });

    cout << "\n--- Sort by DESCENDING price ---" << endl;
    for (const auto& pc : inventory) pc.showInfo();

    return 0;
}


