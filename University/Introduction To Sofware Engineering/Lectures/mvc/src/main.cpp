#include <vector>
#include <string>
#include <iostream>

class Contact {
  public:
    Contact(std::string lname, std::string fname, std::string e): first(fname), last(lname), email(e) {};
    ~Contact() {}

    void setPNum(std::string pn) { pnum = pn; }
    std::string getFirst() { return first; }
    std::string getLast() {return last; }
    std::string getEmail() { return email; }
    std::string getPNum() { return pnum; }

  private:
    std::string first, last, email, pnum;
};

class ContactBookUI {
  public:
    ContactBookUI() {}
    ~ContactBookUI() {}

    virtual void print(std::vector<Contact*> contacts) = 0;
    virtual std::string getPhoneNum() = 0;
};

class ByFirstName : public ContactBookUI{
  public:
    ByFirstName() {}
    ~ByFirstName() {}

    std::string getPhoneNum() { return " "; }
    void print(std::vector<Contact*> contacts){
      for(Contact* c : contacts) {
        std::cout << c->getFirst() << " " << c->getLast() << ": " << c-> getEmail() << std::endl;
      }
    }
};

class ByLastName : public ContactBookUI{
  public:
    ByLastName() {}
    ~ByLastName() {}

    std::string getPhoneNum() {
      std::string pn = "";
      std::cout << "Enter Phone No.: ";
      std::cin >> pn;
      return pn;
    }
    void print(std::vector<Contact*> contacts){
      for(Contact* c : contacts) {
        std::cout << c->getLast() << ", " << c->getFirst() << ": " << c-> getEmail() << " Phone#: " << c->getPNum() << std::endl;
      }
    }
};

class ByEmail : public ContactBookUI{
  public:
    ByEmail() {}
    ~ByEmail() {}

    std::string getPhoneNum() { return " "; }
    void print(std::vector<Contact*> contacts){
      for(Contact* c : contacts) {
        std::cout << c-> getEmail() << ": " << c->getFirst() << " " << c->getLast() << std::endl;
      }
    }
};

class ContactBook {
  public:
    ContactBook(){}
    ~ContactBook() {}

    void setUI(ContactBookUI* i) { ui = i; }
    void add(Contact* c) { contacts.push_back(c); }
    void display() { ui->print(contacts); }
    void getData() {
      for(Contact* c : contacts) {
        std::string pnum = ui->getPhoneNum();
        c->setPNum(pnum);
      }
    }


  private:
    std::vector<Contact*> contacts;
    ContactBookUI* ui;
};

int main(int argc, char const *argv[]) {
  // Create "model" objects
  Contact* instructor = new Contact("Anvik", "Dr.", "john.anvik@uleth.ca");
  Contact* marker = new Contact("Deutekom", "Steve", "mark3720@uleth.ca");

  // Create a collection of "views"
  std::vector<ContactBookUI*> views;
  views.push_back(new ByFirstName());
  views.push_back(new ByLastName());
  views.push_back(new ByEmail());


  // Create the "controller"
  ContactBook* contacts = new ContactBook();
  contacts->add(instructor);
  contacts->add(marker);

  // Use different views
  for(ContactBookUI* ui : views) {
    contacts->setUI(ui);
    contacts->getData();
    contacts->display();
    std::cout << std::endl;
  }

  return 0;
}
