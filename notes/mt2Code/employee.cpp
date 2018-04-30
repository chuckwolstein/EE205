/*problem1*/

class HourlyEmployee: public Employee {
private:
  float wage;
public:
void SetWage (float w) { ...;}
float GetWage(){...;}
void DisplayMyPay() { }
}
/*problem2*/
float SumofHours (Employee x, Employee y) {
  return (x+y); //but you still need to override the plus operator
  //if you didn't override the addition function, you didn't understand
  //templates
}

/*problem3*/
void whoslate(vector<Employee*> wv) {
  it
  (it->GetLateCount() > 0)
}

/*problem 4*/
virtual void DisplayMyPay() = 0;
};

void DisplayEmployeeDetails(Employee e) {
  e.DisplayMyPay();
}
