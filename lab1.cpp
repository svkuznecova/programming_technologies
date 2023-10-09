%факт: газета(id, Название, Жанр, Цена).
газета(1, "Некий кот", развлекательный, 150).
газета(2, "Смешарики", детский, 120).
газета(3, "Вокруг света", научный, 300).
газета(4, "99 дней", развлекательный, 200).
газета(5, "Дача", бытовой, 200).
газета(6, "Рецепты", бытовой, 100).
газета(7, "В мире науки", научный, 175).
газета(7, "Вестник", новостной, 99).
газета(8, "Мурзилка", детский, 199).
газета(9, "Известия", новостной, 149).
газета(10, "Баскетбол", спортивный, 100).
газета(11, "Спорт сегодня", спортивный, 89).
газета(12, "Молодая гвардия", политический, 100).

%факт: подписчик(id, ФИО, возраст, адрес).
подписчик(1, "Петухов Мирон Иванович", 7, "Озерная 55").
подписчик(2, "Алексеев Леонид Егорович", 19, "Миклухо-Маклая 7к2").
подписчик(3, "Овсянников Ярослав Ильич", 20, "Чкалова 45").
подписчик(4, "Никитин Денис Ильич", 19, "Цветочная 23").
подписчик(5, "Селиванов Леон Максимович", 27, "Петровская 3").
подписчик(6, "Тихомирова Полина Кирилловна", 67, "Вокзальная 1").
подписчик(7, "Маркин Артём Германович", 16, "Киролова 27").
подписчик(8, "Ермаков Демид Никитич", 17, "Ульяновская 53").
подписчик(9, "Селезнев Артём Дмитриевич", 25, "Берёзовская 27").
подписчик(10, "Кудряшова Екатерина Алексеевна", 78, "Камнева 27").
подписчик(11, "Сазанов Даниил Саввич", 20, "Солнечная 32").

%факт: подписан(id_подписчика, id_подписки, длительность подписки в месяцах).
подписан(1, 8, 3).
подписан(1, 7, 2).
подписан(2, 6, 4).
подписан(2, 5, 1).
подписан(3, 4, 7).
подписан(3, 3, 1).
подписан(4, 2, 2).
подписан(4, 1, 4).
подписан(5, 12, 6).
подписан(5, 10, 2).
подписан(6, 11, 7).
подписан(6, 9, 1).
подписан(7, 8, 9).
подписан(7, 6, 1).
подписан(8, 7, 8).
подписан(8, 5, 10).
подписан(9, 4, 2).
подписан(9, 2, 4).
подписан(10, 3, 5).
подписан(10, 1, 12).

%правило: вывод название газеты и его цена по жанру.
издание_газеты(Жанр, Название, Цена) :-
газета(_, Название, Жанр, Цена).

%правило: вывод названия газеты и суммы подписки по имени подписчика.
сумма_подписки(Имя, Название, Сумма) :-
газета(Id_газеты, Название, _, Цена),
подписчик(Id_подписчика, Имя, _, _),
подписан(Id_подписчика, Id_газеты, Длительность),
Сумма is Длительность * Цена.

%правило: вывод названии газеты по имени подписчика.
подписчики_газеты(Название, Имя) :-
газета(Id_газеты, Название, _, _),
подписчик(Id_подписчика, Имя, _, _),
подписан(Id_подписчика, Id_газеты, _).

%правило: вывод имени подписчика и название газеты по жанру.
жанр(Жанр, Имя, Название):-
газета(Id_газеты, Название, Жанр, _),
подписан(Id_подписчика, Id_газеты, _),
подписчик(Id_подписчика, Имя, _, _).

%правило: вывод улицы по названию газеты.
доставка(Название, Адрес) :-
газета(Id_газеты, Название, _, _),
подписан(Id_подписчика, Id_газеты, _),
подписчик(Id_подписчика, _, _, Адрес).

%правило; вывод возраста подписчика по его имени.
возраст_пописчика(Имя, Возраст) :-
подписчик(_, Имя, Возраст, _).

%издание_газеты("спортивный", Название, Цена).
%сумма_подписки("Селезнев Артём Дмитриевич", Название, Сумма).
%подписчики_газеты(Название, "Селиванов Леон Максимович").
%жанр("детский", Имя, Название).
%доставка("Дача", Адрес).
%возраст_пописчика("Кудряшова Екатерина Алексеевна", Возраст).
