# Tugas Kecil I Strategi Algoritma

# Penyelesaian Permainan Kartu 24 dengan Algoritma Brute Force

## Deskripsi singkat
Program ini akan menerima input pengguna berupa empat karakter yang merupakan bagian dari dari (A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K) atau menghasilkan input secara random kemudian program akan menemukan seluruh kemungkinan operasi yang dapat menghasilkan angka 24. Program akan mengeluarkan output berupa banyaknya solusi, seluruh solusi, dan waktu eksekusi. Banyaknya solusi serta seluruh solusi dapat disimpan di dalam file. Program ini berbasis Command Line Interface (CLI) dan ditulis dalam bahasa C++.

## Cara melakukan kompilasi
1. Pada direktori utama, lakukan kompilasi dengan memasukkan perintah berikut pada command prompt.
    ...
    g++ src/iofile.cpp src/algorithm.cpp src/driver.cpp -o bin/driver 
    ...

2. Jalankan program dengan memasukkan perintah berikut.
    ...
    ./bin/driver
    ...

## Cara menggunakan program
1. Anda dapat memilih untuk menginput kartu secara langsung atau generate kartu random. Ketik 0 untuk input kartu atau ketik 1 untuk generate kartu random.
    ...
    Do you want to insert cards (0) or generate random cards (1)?:
    ...

2. Jika Anda memilih untuk input kartu, masukkan empat karakter (A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K) yang dibatasi tanda spasi.
    ...
    Insert card numbers:
    A 3 Q 8
    ...

3. Jika Anda memilih untuk generate kartu random, maka kartu akan ditampilkan di layar.
    ...
    Your cards: 
    2 10 5 10 
    ...

4. Setelah itu, banyak solusi, semua solusi, dan waktu eksekusi akan ditampilkan di layar.

5. Anda dapat memilih untuk menyimpan solusi ke dalam file. Ketik Y untuk menyimpan solusi atau N jika tidak ingin menyimpan solusi.
    ...
    Do you want to save the result? (Y/N): Y
    ...

6. Masukkan nama file untuk menyimpan solusi. Kemudian, file akan disimpan di folder test
    ...
    Do you want to save the result? (Y/N): Y
    Insert file name: testcase1.txt
    ...

## Identitas author