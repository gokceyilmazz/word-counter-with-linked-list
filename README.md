# word-counter-with-linked-list
 
I. Problem tanımı
  Verilen bir text dosyasından dosyadan okuma yöntemiyle alınan kelimelerin, kelime adetleri de hesaplanarak bir kelime bağlı listede birden fazla bulunmayacak şekilde bağlı listeye eklenmesi istenmiştir. 
  Kelime sayıları bağlı listeye eklenmeden önce hesaplanmıştır ve başa ekle, sona ekle, araya ekle fonksiyonları kullanılarak kelimeler eklenmiştir. Bağlı listede kelimeler kelime adetlerine göre büyükten küçüğe sıralanmıştır. Konsol çıktısında her bir kelimenin yanında kelimenin text içinde bulunma sayısı gösterilmiştir.
II. Yapılan araştırmalar
  Öncelikle ekleme fonksiyonlarını yazarak manuel olarak eleman eklemesi denemesi yaptık ve fonksiyonlarımız çalışma durumunu test ettik. Başa ekle, sona ekle ve araya ekle fonksiyonlarını yazarken veri yapıları ve algoritmaları dersinden öğrendiklerimizi kullandık.
  İlk olarak dosyadan alırken karakter olarak alarak strtok fonksiyonu yardımıyla her boşlukta keyword değişkenine atadık. Fakat bu yöntem daha sonra çalışmamızı zorlaştırdığı ve sağlıklı bir yöntem olmadığı için vazgeçtik. Onun yerine daha sonra genel yapı bölümünde de anlatacağımız dosyayı while döngüsü kullanarak iki kere okuyarak dosyadan aldığımız kelimenin dosya içinde tekrar bulunup bulunmadığını test etme sorununu da çözmüş olduk.
  Projemiz sürecinde kullanacağımız strcpy ve strcmp fonksiyonlarını araştırdık [1] [2]. Kullanımlarını anlatımlar üzerinden öğrendik ve kendi kodumuzda kullandık.
 



 Türkçe karakterler okunduğunda konsolda ekran çıktısı verilirken kelimelerdeki Türkçe karakterlerin görünüşü açısından problem yaşadık. Yaşadığımız bu problemi çözmek için internetten yaptığımız araştırmalar sonucunda c programlama dilinde Türkçe karakter desteğini belirtmek için locale.h kütüphane dosyası içindeki setlocale fonksiyonunun kullanıldığını öğrendik ve [3] [4]   local.h kütüphanesini ekleyerek setlocale fonksiyonuyla Türkçe dil desteği sağladık. Setlocale fonksiyonu parametre olarak iki değer alır. İlk değer LC_TIME, LC_NUMERIC, LC_ALL, LC_MESSAGES vb. değerleri içeren tanım alanını belirtir. İkinci değer ise kullanılacak dili belirtir.  
  Kodumuz üzerinde gerekli eklemeleri yaptıktan sonra okuyacağımız dosyanın kodlamasını ANSI olarak değiştirdik ve problemi çözmüş olduk. 
 Son olarak rapor isterlerinden olan yazılım mimarisi çıkartmayı araştırdık ve nasıl yapacağımıza karar verdik [5] [6] [7] [8]. Yazılım mimarisinin daha büyük çaplı projelerde yapıldığını gördük ve kendi projemize uyarlamaya çalıştık. Mimariyi açıklamak adına yalancı kod kullanmaya karar verdik.
