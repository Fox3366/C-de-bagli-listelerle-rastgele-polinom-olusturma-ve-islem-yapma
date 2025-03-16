# C-de-bagli-listelerle-rastgele-polinom-olusturma-ve-islem-yapma
Yazilim Müh. 1.sınıf 2.dönem bagli listeler ödevim

Kod C dilinde bağlı listeler ile iki adet polinomu verilen değer kadar eleman içerecek şekilde ve polinom elemanlarını rastgele olarak üretmektedir.

Polinomlar üretilirken bağlı listeye derece sırasına göre eklenmektedir bu da normal polinom gösterimi ile aynıdır. Örneğin: 4x^4 + 1x^3 + 7x^1 + 5

Üretilen polinomlar seçilen işleme göre kullanıcıya gösterilir.

Verilen bir x değerine yani polinomun değişken değerine göre polinomların sonucunu hesaplamakta ve ekrana yazdırmaktadır.

Sonrasında polinom derecesine göre polinomlardan verilen dereceye uygun elemanlar silinir.

İki polinomu derecelere göre normal polinom toplaması olarak toplayabilir.

Polinomlarda bir derece bir kez olacak şekilde ve de bir katsayı bir kez olacak şekilde rastgele üretilmektedir, her derece ve katsayıdan aynı polinomda yalnızca 1 adet bulunabilir. Örneğin: ✅ 6x^2 + 5x^1 + 4 ---> doğru örnek, ❌ 6x^3 + 5x^3 ---> yanlış örnek

Katsayılar 0-10 arası dereceler ise 0-6 arası sayılardan rastgele seçilmektedir, dereceler birbirinden farklı olacağı için polinom max 7 elemanlı olabilir aksi durumda kod uyarı vermekte ve yeni değer istemektedir.

Kodda üretilmiş polinomun üzerine yeni polinomlar üretilmek istenirse kod önceki polinomu temizler ve sonrasında yenisini oluşturur böylelikle polinomlar tekrar üretildiğinde çakışma olmaz.

Kodun amacı sade ve basittir, bağlı listeler konusunu geliştirmek için yapılmış bir örnektir.

Tüm bunları tek yönlü bağlı liste ile gerçekleştirir.


English: 
Generating and Performing Operations on Random Polynomials Using Linked Lists in C

This is an assignment for the second semester of the first year in Software Engineering.

The code, written in C, generates two polynomials using linked lists. Each polynomial contains a specified number of elements, and its terms are generated randomly.

While generating the polynomials, elements are inserted into the linked list in order of degree, maintaining the standard polynomial representation. For example:
4x⁴ + 1x³ + 7x¹ + 5

The generated polynomials are displayed based on the selected operation.

The program calculates the result of the polynomials for a given x value (i.e., the polynomial variable).

It also removes terms from the polynomials based on the specified degree.

The two polynomials can be added together according to polynomial addition rules, considering their degrees.

Each polynomial term is uniquely generated—each degree appears only once, and each coefficient is used only once per polynomial.
For example:
✅ 6x² + 5x¹ + 4 → Correct
❌ 6x³ + 5x³ → Incorrect

Coefficients are randomly chosen between 0 and 10, while degrees range between 0 and 6.

Since degrees must be unique, a polynomial can have a maximum of 7 terms. Otherwise, the program prompts the user for new values.

If a new polynomial is generated, the previous one is cleared to prevent conflicts.

This program serves as a simple and practical example for improving understanding of linked lists.

It uses a singly linked list to accomplish all operations.
