/*
this program is to experiment with using one map to check another map
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

//print out what is in officeSupplies
  for(Inventory::const_iterator it1 = officeSupplies.begin();
    it1 != officeSupplies.end();
    ++it1) {
      std::cout << it1->first << " => " << it1->second << '\n';
  }

  Inventory supplyRequest;
  supplyRequest ["pens"] = 2;
  supplyRequest ["erasers"] = 3;

  bool canFill = TRUE;

//use the supplyRequest map to check the inventory
  for(Inventory::const_iterator it0 = supplyRequest.begin();
    it0 != supplyRequest.end();
    ++it0) {

    }

  return 0;
}
