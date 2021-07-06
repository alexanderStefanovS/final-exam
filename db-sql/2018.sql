
----- 07.2018 - 1 -----

select s.name, min(m.year) as first_film, max(m.year) as last_film
from studio s join movie m on s.name = m.studioname
where s.name like 'M%'
group by s.name

----- 07.2018 - 2 -----

select m.name, count(*)
from moviestar m join starsin si on m.name = si.starname
where m.gender = 'F'
group by m.name
having count(*) >= all (select count(*) 
                        from moviestar m join starsin si on m.name = si.starname
                        where m.gender = 'F'
					    group by m.name)