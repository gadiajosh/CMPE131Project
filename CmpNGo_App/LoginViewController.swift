//
//  LoginViewController.swift
//  CmpNGo_App
//
//  Created by Josh Gadia on 10/30/18.
//  Copyright © 2018 Josh Gadia. All rights reserved.
//

import UIKit

class LoginViewController: UIViewController {

    @IBOutlet weak var user_email_textfield: LoginTextField!
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func EnterButton_tapped(_ sender: Any) {
        let userEmail = user_email_textfield.text;
        
        //Checks for Empty Fields
        if (userEmail?.isEmpty)!{
            
            //Displays Alert Message
            displayAlertMessage(userMessage: "Must enter a SJSU email.");
            return
        }
        
        //Checks if SJSU Email is being used
        let substring = "@sjsu.edu";
        if (userEmail?.contains(substring))!{
            return;
        }
        else{
            displayAlertMessage(userMessage: "Not a valid SJSU email.");
        }
        
    }

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

    //Function to display Alert Mesaage
    func displayAlertMessage(userMessage:String)
    {
        
        var myAlert = UIAlertController(title:"Alert", message:userMessage, preferredStyle: UIAlertControllerStyle.alert);
        
        let okAction = UIAlertAction(title:"Ok", style:UIAlertActionStyle.default, handler:nil);
        
        myAlert.addAction(okAction);
        
        self.present(myAlert, animated:true, completion:nil);
        
}

}
