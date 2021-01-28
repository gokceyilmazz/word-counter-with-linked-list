# word-counter-with-linked-list
 
 # I. Problem tanımı
  Verilen bir text dosyasından dosyadan okuma yöntemiyle alınan kelimelerin, kelime adetleri de hesaplanarak bir kelime bağlı listede birden fazla bulunmayacak şekilde bağlı listeye eklenmesi istenmiştir. 
  Kelime sayıları bağlı listeye eklenmeden önce hesaplanmıştır ve başa ekle, sona ekle, araya ekle fonksiyonları kullanılarak kelimeler eklenmiştir. Bağlı listede kelimeler kelime adetlerine göre büyükten küçüğe sıralanmıştır. Konsol çıktısında her bir kelimenin yanında kelimenin text içinde bulunma sayısı gösterilmiştir.

# II. Yapılan araştırmalar
  Öncelikle ekleme fonksiyonlarını yazarak manuel olarak eleman eklemesi denemesi yaptık ve fonksiyonlarımız çalışma durumunu test ettik. Başa ekle, sona ekle ve araya ekle fonksiyonlarını yazarken veri yapıları ve algoritmaları dersinden öğrendiklerimizi kullandık.
  İlk olarak dosyadan alırken karakter olarak alarak strtok fonksiyonu yardımıyla her boşlukta keyword değişkenine atadık. Fakat bu yöntem daha sonra çalışmamızı zorlaştırdığı ve sağlıklı bir yöntem olmadığı için vazgeçtik. Onun yerine daha sonra genel yapı bölümünde de anlatacağımız dosyayı while döngüsü kullanarak iki kere okuyarak dosyadan aldığımız kelimenin dosya içinde tekrar bulunup bulunmadığını test etme sorununu da çözmüş olduk.
  Projemiz sürecinde kullanacağımız strcpy ve strcmp fonksiyonlarını araştırdık [1] [2]. Kullanımlarını anlatımlar üzerinden öğrendik ve kendi kodumuzda kullandık.
 



 Türkçe karakterler okunduğunda konsolda ekran çıktısı verilirken kelimelerdeki Türkçe karakterlerin görünüşü açısından problem yaşadık. Yaşadığımız bu problemi çözmek için internetten yaptığımız araştırmalar sonucunda c programlama dilinde Türkçe karakter desteğini belirtmek için locale.h kütüphane dosyası içindeki setlocale fonksiyonunun kullanıldığını öğrendik ve [3] [4]   local.h kütüphanesini ekleyerek setlocale fonksiyonuyla Türkçe dil desteği sağladık. Setlocale fonksiyonu parametre olarak iki değer alır. İlk değer LC_TIME, LC_NUMERIC, LC_ALL, LC_MESSAGES vb. değerleri içeren tanım alanını belirtir. İkinci değer ise kullanılacak dili belirtir.  
  Kodumuz üzerinde gerekli eklemeleri yaptıktan sonra okuyacağımız dosyanın kodlamasını ANSI olarak değiştirdik ve problemi çözmüş olduk. 
 Son olarak rapor isterlerinden olan yazılım mimarisi çıkartmayı araştırdık ve nasıl yapacağımıza karar verdik [5] [6] [7] [8]. Yazılım mimarisinin daha büyük çaplı projelerde yapıldığını gördük ve kendi projemize uyarlamaya çalıştık. Mimariyi açıklamak adına yalancı kod kullanmaya karar verdik.
 
 # III. Yazılım mimarisi
  Projenin ana yapısı kelimeleri dosyadan okuyup tekrarlanmayı test etmek amacıyla dosyayı tekrar açıp okuması ve bunu her kelime için tekrarlamasından oluşuyor. Daha sonra alınan kelimeler ekleme fonksiyonlarına gönderilerek bağlı listeye ekleniyor. Tüm bunları yalancı kod kullanarak açıklayabiliriz.
1.	Başla
2.	Dosyayı aç
3.	Kelimeyi oku
4.	ListeyeEkle fonksiyonuna gönder
5.	Dosyayı tekrar aç
6.	Kelime tekrar var mı kontrol et
7.	Varsa kelime sayısını arttır
8.	ArayaEkle fonksiyonuna gönder
9.	Döngüyü tekrar et
10.	Dosya bittiğinde döngüden çık
11.	Kelimeleri yazıdır
12.	Bitir

# IV. Genel yapı
  Projemiz main ana fonksiyonun yanında SonaEkle, Basaekle, ArayaEkle, kontrol, ListeyeEkle ve yazdir fonksiyonlarından oluşmaktadır. Projenin genel yapısında kod karmaşasını önlemek açısından bu şekilde metotlarla çalışmayı tercih ettik. İlk olarak dosya adında bir FILE tanımladık ve text dosyasını fopen fonksiyonuyla açtık. Dosyanın var olma durumunda işlemlerin yapılması için if else blokları kullandık. Dosyanın var olmama durumunda yani dosya!=NULL olmama durumunda else bloğu devreye girdi ve okunacak dosyanın bulunamadığını yazdırdık.
  Dosyanın var olduğu durumda if bloğunun içine girdik ve dosyanın sonuna gelene kadar devam eden while döngüsü açtık. Char keyword[200] değişkeni belirledik ve fscanf fonksiyonuyla dosyadan okuduğumuz kelimeyi bu değişkene attık. Bağlı listede var olan bir kelimeyi tekrar eklememek için okunan kelimeyi kontrol fonksiyonuna gönderdik. Eğer kelime daha önce bağlı listeye eklenmişse fonksiyon 0 değeri döndürdü, eklenmemişse 1 değeri döndürdü. Kontrol fonksiyonunun gönderdiği değeri tempControl değişkenine atadık ve bu değerin 1 olması durumunda sonraki işlemleri gerçekleştirdik. Elde ettiğimiz keyword değişkenini void bir fonksiyon olan ListeyeEkle fonksiyonuna parametre olarak gönderdik. ListeyeEkle fonksiyonunun içinde tempdosya adında bir FILE daha oluşturduk ve while döngüsü ile text dosyasını tekrar okuduk ve kelimenin tekrarlayıp tekrarlamadığını test ettik. İkinci okumada okuduğumuz kelimeleri geçici olarak kullanmak için tempkelime değişkenine atadık. Keyword ve tempkelimenin aynı olup olmadığını test etmek için strcmp fonksiyonunu kullandık. Aynı olmaları durumunda bir int değişken olan kelimeadeti bir arttırdık. While döngüsünden çıkıp ArayaEkle fonksiyonuna kelimeadet ve keyword değişkenlerini yolladık. Bu döngüyü dosyanın sonuna gelene kadar sürdürdük.
  ArayaEkle fonksiyonuna değer gönderildiğinde eğer liste boşsa gönderilen kelime ve kelime sayısı bağlı listenin ilk düğümüne atanır. Eğer liste boş değilse eklenecek kelimenin kelime sayısının listenin başındaki düğümdeki kelimenin kelime sayısından büyük olup olmadığına bakılır. Eğer büyükse kelime BasaEkle fonksiyonuna gönderilir. Değilse listenin sonundaki düğümdeki kelimenin kelime sayısından küçük olup olmadığına bakılır. Eğer küçükse SonaEkle fonksiyonuna gönderilir. İki durumda sağlanmıyorsa else bloğu devreye girer ve kelime sayısı kendinden öncekilerden küçük olacak şekilde araya eklenir.
  BasaEkle fonksiyonunda eğer bağlı liste boşsa gelen kelimeyi start düğümüne ekler. Eğer bağlı liste boş değilse start düğümünü eklenecek düğümün nexti yapar ve eklenecek kelimeyi başa getirir.
  SonaEkle fonksiyonunda ise eğer bağlı liste boşsa gelen kelimeyi start düğümüne ekler. Eğer bağlı liste boş değilse end düğümünün nextine eklenecek düğümünü koyar ve kelimeyi bu düğüme atar.
  Okunan kelimelerin bu fonksiyonlara gitmesi dosyanın sonuna kadar devam eder. Dosya bittiğinde while döngüsünden çıkılır ve yazdir fonksiyonu çağrılır. Bu fonksiyonda da bağlı liste traverse işlemine tabi tutulur ve liste baştan sona gezilir, her düğümün kelime ve kelime sayısı yazdırılır. Kelimelerin sırasını ve toplam kelime sayısını belirtmek için int i değişkeni tanımlanır ve 1’den başlatılır. While döngüsü boyunca i arttırılır ve yazdırılır.
  Yazdırma fonksiyonundan çıktıktan sonra program sona erer.


