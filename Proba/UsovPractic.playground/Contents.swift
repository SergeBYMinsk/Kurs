import UIKit

import Foundation

//
//var oneNum: Int8
//var twoNum: UInt8
//
//oneNum = Int8.min
//twoNum = UInt8.max
//
//print("\(oneNum) \(twoNum)")
//
//var foneNum: Int = 15
//var ftwoNum = 10
//var ftmpNum: Int
//
//ftmpNum = foneNum
//foneNum = ftwoNum
//ftwoNum = ftmpNum
//print("первая переменная = \(foneNum) вторая переменная = \(ftwoNum)")




//let numOne: Float = 45.8
//let numTwo: Float
//var numThree: Double
//
//numTwo = 12.4
//numThree = 45.45



//let numOne: Int, numTwo: Float, numTree: Double
//numOne = 18; numTwo = 16.4; numTree = 5.7
//
//let resSum = Float(numOne) + numTwo + Float(numTree)
//let resMult = Int(Float(numOne) * numTwo * Float(numTree))
//var res = Double(numTwo.truncatingRemainder(dividingBy: Float(numTree)))
//print("результат сложения = \(resSum) результат умножения = \(resMult) результат остатка от деления = \(res)")



//(a+4b)(a–3b)+a2
//var a = 2
//var b = 3
//var res = (a + 4 * b) * (a - (3 * b)) + (a * a)
//
////2(c+1)2+3(d+1)
//var c = 1.75
//var d = 3.25
//var i = pow(c+1, 2)
//var res1 = 2 * i * 2 + 3 * ( d + 1 )




//var myString: String = "my world"
//let myCharacter: Character = "F"
//var numOne: Int = 2
//var numTwo: Int = 4
//let res = String(myString) + String(myCharacter) + String(numOne + numTwo)
//print("\(res)")




//var day = 28
//var month = " Октября "
//var year = 1980
//let myBirthDay = String(String(day) + month + String(year))
//print("\(myBirthDay)")
//



//var myFistBool = true
//var mySecondBool = false
//let one = myFistBool && mySecondBool
//let two = mySecondBool || myFistBool
//print(mySecondBool, myFistBool)




//let myName:String = "Сергей"
//let myWeight: Double = 120
//let myHeight: Int = 197
//let myHeightMeters = (Double(myHeight) / 100)
//
//let imb = Double(myWeight / Double(myHeightMeters * myHeightMeters))
//
//print("Индекс массы тела \(myName) состовляет \(imb)")
//
//if imb < 16 {
//    print("Выраженный дефицит массы тела")
//} else if imb < 18.5 {
//    print("Недостаточная (дефицит) масса тела")
//} else if imb < 24.99 {
//    print("Норма")
//} else if imb < 30 {
//    print("Избыточная масса тела (предожирение)")
//} else if imb < 35 {
//    print("Ожирение")
//} else if imb < 40 {
//    print("Ожирение резкое")
//} else if imb > 40 {
//    print("Очень резкое ожирение")
//}




//Кортежи

//var myLikes: (favFilm: String, favNum: Int, favFood: String) = ("Терминатор", 13, "Оливье")
//var youLikes: (favFilm: String, favNum: Int, favFood: String) = ("С лёгким паром", 1980, "Картофель")
//var tmp: (favFilm: String, favNum: Int, favFood: String)
//
//var (myFavFilm, myFavNum, myFavFood) = myLikes
//
//tmp = myLikes
//myLikes = youLikes
//youLikes = tmp
//
//var third = (myLikes.favNum, youLikes.favNum, myLikes.favNum - youLikes.favNum)






//typealias Text = String
//let fist: Text = "12345"
//let second: Text = "54321"
//let third: Text = "abc123"
//if (Int(fist) != nil) {print(fist)}
//if (Int(second) != nil) {print(second)}
//if (Int(third) != nil) {print(third)}
//
//typealias TupleType = (numberOne: Text?, numberTwo: Text?)?
//var numOne: TupleType = ("190", "67")
//var numTwo: TupleType = ("100", nil)
//var numTree: TupleType = ("-65", "70")
//
//if let (one, two) = numOne {
//    if one != nil && two != nil {
//        print(numOne!.0!, numOne!.1!)
//    }
//}
//if let (one, two) = numTwo {
//    if one != nil && two != nil {
//        print(numTwo!.0!, numTwo!.1!)
//    }
//}
//if let (one, two) = numTree {
//    if one != nil && two != nil {
//        print(numTree!.0!, numTree!.1!)
//    }
//}
//
//
//



//typealias Operation = (operandOne: Float, operandTwo: Float, operandThree: Float, operation: Character)
//
//let tupleOfOperation: Operation = (14, 54.2, 16.2, "+")
//
//switch tupleOfOperation {
//case (var one, var two, var three, "*"):
//    let result = one * two * three
//    print(result)
//    break
//case (var one, var two, var three, "+"):
//    let result = one + two + three
//    print(result)
//    break
//    case (var one, var two, var three, "-"):
//    let result = one - two - three
//    print(result)
//    break
//    case (var one, var two, var three, "/"):
//    let result = one / two / three
//    print(result)
//    break
//default:
//    print("Проверь значения")
//}







//typealias Chessman = [String: (alpha:Character,num:Int)?]
//
//var Chessmans: Chessman = ["White King":("C",6), "Black Rook":("E",2), "Black Bishop":nil]
//
//
//for (name, coordinates) in Chessmans {
//    if coordinates != nil {
//        print("Coordinates of \(name) is \(coordinates)")
//    }else{
//        print("\(name) id dead")
//    }
//}

//if let coordinates = Chessmans ["White King"]!{
//    print("Coordinates of White King is \(coordinates)")
//} else {
//    print("White King id dead")
//}
//if let coordinates = Chessmans ["Black Rook"]!{
//    print("Coordinates of Black Rook is \(coordinates)")
//} else {
//    print("Black Rook id dead")
//}
//if let coordinates = Chessmans ["Black Bishop"]!{
//    print("Coordinates of Black Bishop is \(coordinates)")
//} else {
//    print("Black Bishop id dead")
//}


//ВНИМАНИЕ! При опциональном связывании используется принудительное извлечение опционального значения (символ «!» после ссылки на элемент словаря Chessmans). Это связано с тем, что словарь всегда возвращает опционал, а так как значение каждого элемента словаря так же является опционалом, то будет возвращен кортеж типа
//






var str: String!

if let str = str {
    print(str)
} else {
    print("str Nil")
}
