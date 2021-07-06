
----- 09.2010 - 1 -----

SELECT DISTINCT name
from moviestar m left join starsin si on m.name = si.starname
where si.movieyear <= 1970;

----- 09.2010 - 2 -----

SELECT m.name, min(si.movieyear - year(m.birthdate))
from moviestar m 
	join starsin si on m.name = si.starname
group by name;