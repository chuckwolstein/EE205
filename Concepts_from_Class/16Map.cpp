/* Map */

/*
Map is dictionary like data structure. It is a sequence of (key, value) pair,
where only single value is associated with each unique key. It is often referred
as associative array.

In map, key values are generally used to sort the elements. For map data type of
key and value can differ and it is represented as:
*/

typedef pair<const Key, T> value_type;

/*
Zero sized maps are also valid. In that case map.begin() and map.end() points to
same location. Let's look at the following example where we are associating
strings with a character. ( students name associated with a character grade)
*/

std::map <string, char> grade_list;

/*
Now, to actually store or access data in the map, all you need to do is treat it
like a normal array and use brackets. The only difference is that you no longer
use integers for the index -- you use whatever data type was used for the key.

For instance, following the previous example, if we wanted to assign a grade of
'B' to a student named "John", we could do the following:
*/

 grade_list["John"] = 'B';

/*
If we later decided that John's grades had improved, we could change his grade
in the same fashion:
*/

grade_list["John"] = 'B';

// John's grade improves
grade_list["John"] = 'A';

/*
So adding keys to a map can be done without doing anything special -- we just
need to use the key and it will be added automatically along with the
corresponding data item. On the other hand, getting rid of an element requires
calling the function erase, which is a member of the map class:
*/

erase(key_type key_value);

/*
For instance, to erase "John" from our map, we could do the following:
*/

grade_list.erase("John");

/* Functions associated with Map: */

begin() – Returns an iterator to the first element in the map

end() – Returns an iterator to the theoretical element that follows last element in the map

size() – Returns the number of elements in the map

max_size() – Returns the maximum number of elements that the map can hold

empty() – Returns whether the map is empty

pair insert(keyvalue,mapvalue) – Adds a new element to the map

erase(iterator position) – Removes the element at the position pointed by the iterator

erase(const g)- Removes the key value ‘g’ from the map

clear() – Removes all the elements from the map

key_comp() / value_comp()   // – Returns the object that determines how the
                            // elements in the map are ordered (‘<' by default)

find(const g)    // – Returns an iterator to the element with key value ‘g’ in the
                //map if found, else returns the iterator to end

count(const g)  // – Returns the number of matches to element with key value ‘g’
                // in the map

lower_bound(const g)    // – Returns an iterator to the first element that is
                        // equivalent to mapped value with key value ‘g’ or
                        // definitely will not go before the element with key
                        //value ‘g’ in the map

upper_bound(const g)    // – Returns an iterator to the first element that is
                        // equivalent to mapped value with key value ‘g’ or
                        // definitely will go after the element with key value
                        // ‘g’ in the map

/*
This is what the map template really looks like:
*/

std::map <key_type, data_type, [comparison_function]>

/*
Notice that the comparison function is in brackets, indicating that it is
optional so long as your key_type has the less-than operator, <, defined -- so
you don't need to specify a comparison function for so-called primitive types
such as int, char, or even for the string class. Moreover, if you overloaded
the < operator for your own class, this won't be necessary.

The reason that the key type needs the less-than operator is that the keys will
be stored in sorted order -- this means that if you want to retrieve every key,
value pair stored in the map, you can retrieve them in the order of the keys.
*/
