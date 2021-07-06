
----- 07.2017 - 1 -----

SELECT studioname, title, year 
FROM movie m WHERE year = (SELECT max(year) 
						   FROM movie 
						   WHERE m.studioname = studioname);

----- 07.2017 - 2 -----

SELECT name, sum(length)
FROM movieexec JOIN movie ON `producerc#` = `cert#`
where `producerc#` in (select `cert#` from movie where length < 1980)
group by name;

----- 07.2017 - 3 -----

SELECT starname, title, name, networth
FROM starsin 
JOIN movie ON movietitle = title AND movieyear=year
JOIN (SELECT `cert#`, networth, name
      FROM movieexec
      WHERE networth = (select max(networth) from movieexec)) t on t.`cert#` = `producerc#`;

----- 07.2017 - 4 -----

SELECT name, title, year
FROM movie JOIN movieexec ON `producerc#` = `cert#`
WHERE `cert#` = ANY (SELECT `producerc#` FROM movie WHERE title = 'Interstellar');
