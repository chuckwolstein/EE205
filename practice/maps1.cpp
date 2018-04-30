/*
From various header files in lab 6:

  using Ingredient = std::string;
  using IngredientMap = std::map<Ingredient, unsigned>;
  using Storeroom = IngredientMap;
*/

#include <map>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using Inventory = std::map<string, int>; //make an alias for inventories to
                                         //save on typing later

int main() {
  Inventory officeSupplies; // declare a new map that will hold
                            // my office supply inventory results
  officeSupplies ["pencils"] = 20; //create some new entries in my map
  officeSupplies ["pens"] = 30;
  officeSupplies ["staples"] = 5000;
  officeSupplies ["erasers"] = 10;
  officeSupplies ["markers"] = 22;
  officeSupplies ["pencil refills"] = 4;
  officeSupplies ["paper reams"] = 2;
  officeSupplies ["pencils"] += 1;


  for(Inventory::const_iterator it1 = officeSupplies.begin();
    it1 != officeSupplies.end();
    ++it1) {
      std::cout << it1->first << " => " << it1->second << '\n';
  }
return 0;
}
