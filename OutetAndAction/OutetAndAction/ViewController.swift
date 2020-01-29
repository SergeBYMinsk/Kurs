//
//  ViewController.swift
//  OutetAndAction
//
//  Created by Sergey Sterlikov on 3/10/19.
//  Copyright © 2019 Sergey Sterlikov. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
   
   
    @IBOutlet weak var label: UILabel!
    
    

    @IBAction func changeTextInLabel(_ sender: Any) {
    print(label.text!)
    }
}

