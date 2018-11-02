//
//  SellViewController.swift
//  CmpNGo_App
//
//  Created by Josh Gadia on 11/1/18.
//  Copyright © 2018 Josh Gadia. All rights reserved.
//

import UIKit
import Firebase
import FirebaseDatabase

class SellViewController: UIViewController {
    
    var refItem: DatabaseReference!
    

    @IBOutlet weak var TextFieldItem: UITextField!
    @IBOutlet weak var TextFieldPrice: UITextField!
    @IBOutlet weak var TextFieldCond: UITextField!
    
    
    @IBAction func ButtonPost(_ sender: UIButton) {
        
        //Checks for Empty Fields

        
        addItem()
        displayAlertMessage(userMessage: "Item has been posted!");
    }
    
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        
        FirebaseApp.configure()
        
        refItem = Database.database().reference().child("items");
        
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */
    
    //Function to Add Items into Database
    func addItem(){
        let key = refItem.childByAutoId().key
    
        let item = [ "id": key,
    "itemName": TextFieldItem.text! as String,
    "itemPrice": TextFieldPrice.text! as String,
    "itemCond": TextFieldCond.text! as String,
    ]
    refItem.child(key!).setValue(item)
    }
    
    func displayAlertMessage(userMessage:String)
    {
        
        var myAlert = UIAlertController(title:"Alert", message:userMessage, preferredStyle: UIAlertControllerStyle.alert);
        
        let okAction = UIAlertAction(title:"Ok", style:UIAlertActionStyle.default, handler:nil);
        
        myAlert.addAction(okAction);
        
        self.present(myAlert, animated:true, completion:nil);
        
    }
    
}


