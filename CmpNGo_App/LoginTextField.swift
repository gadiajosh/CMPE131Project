 //
//  LoginTextField.swift
//  CmpNGo_App
//
//  Created by Josh Gadia on 10/29/18.
//  Copyright © 2018 Josh Gadia. All rights reserved.
//

import UIKit

 @IBDesignable
class LoginTextField: UITextField {

        override func layoutSubviews() {
        super.layoutSubviews()
        
        self.layer.borderColor = UIColor(white: 231 / 255, alpha: 1).cgColor
        self.layer.borderWidth = 1
        
    }
    
    override func textRect(forBounds bounds: CGRect) -> CGRect {
        return bounds.insetBy(dx: 8, dy: 7)
    }
    
    override func editingRect(forBounds bounds: CGRect) -> CGRect {
        return textRect(forBounds: bounds)
    }


}
