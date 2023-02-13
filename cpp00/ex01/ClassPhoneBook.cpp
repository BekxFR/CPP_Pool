

class PhoneBook {
  constructor(maxSize) {
    this.maxSize = maxSize;
    this.contacts = [];
  }

  addContact(contact) {
    if (this.contacts.length < this.maxSize) {
      this.contacts.push(contact);
    } else {
      console.log("Phonebook is full");
    }
  }

  removeContact(name) {
    for (let i = 0; i < this.contacts.length; i++) {
      if (this.contacts[i].name === name) {
        this.contacts.splice(i, 1); // remove the contact at index i from the array and only remove 1 element from the array starting at index i  
        break; // stop looping once we have found and removed the contact we are looking for 
      } else { // if we reach here it means that we did not find the contact in our phonebook so we can log a message to let the user know 
        console.log("Contact not found");  										   }  			}  	}

  searchByName(name) { // method to search for a contact by name in our phonebook 

    for (let i = 0; i < this.contacts.length; i++) {

      if (this.contacts[i].name === name) { // check if the current contact's name matches what we are looking for 

        return this.contacts[i]; // return the contact object that matches what we are looking for  

      } else { // if we reach here it means that we did not find a matching contact in our phonebook so we can log a message to let the user know  

        console.log("Contact not found");  

      }  

    }  

  }  

 class Contact{//class Contact pour creer des contacts pour le PhoneBook ci-dessus 

 constructor(name, number){//constructeur qui prend en parametre le nom et le numero du contact que l'on veut creer 

     this._name=name;//attributs prives de la classe Contact qui ne peuvent