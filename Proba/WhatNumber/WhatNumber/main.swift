//
//  main.swift
//  WhatNumber
//
//  Created by Sergey Sterlikov on 7/8/19.
//  Copyright © 2019 Sergey Sterlikov. All rights reserved.
//

import Foundation

let randomNumber = UInt8(arc4random_uniform(100))

print ("Компьютер случайным образом загадал число. Вам требуется отгадать его.")

var correctNumber:Bool = false

while !correctNumber {
    
    print("Введите ваш вариант и нажмите Enter")
    
    let myNumber = readLine()
    
    if (UInt8(myNumber!) == randomNumber){
        correctNumber = true
        
        print("Вы угадали!")
    }
    else if (UInt8(myNumber!)! <= randomNumber){
        print("Ваш вариант меньше загаданного числа")
    }
    else if (UInt8(myNumber!)! >=  randomNumber){
        print("Ваш вариант больше загаданного числа")
        
    }
    
}
while !correctNumber {
    print("Введите ваш вариант  и нажмите Enter")
    let myNumber = readLine()
    switch UInt8(myNumber!)! {
    case randomNumber:
    

        correctNumber = true
        print("Вы угадали!")
    case _ where UInt8(myNumber!)! < randomNumber:
    print("Ваш вариант меньше загаданного числа")
    case _ where UInt8(myNumber!)! > randomNumber:
    print("Ваш вариант больше загаданного числа")
    default:
    
    break;
        
    }
    
}
