
----- 09.2020 - 1 -----

select s.name, s.address 
from studio s 
where 
(select count(*) from movie m where m.studioname = s.name and incolor = 'Y') > 0 
and 
(select count(*) from movie m where m.studioname = s.name and incolor = 'N') > 0;

----- 09.2020 - 2 -----

select s.name, s.address, ave(m.length), count(*)
from studio s left join movie m on s.name = m.studioname
group by s.name
having count(*) <= 3;

----- 07.2020 - 1 -----

--- 1 ---

select ms.name, ms.birthdate, count(*)
from moviestar ms join starsin si on ms.name = si.starname
where 
	ms.name not like '%Jr.%' 
and 
	si.movietitle in (select m.title from movie m where m.incolor = 'Y')
group by ms.name
order by ms.birthdate desc, ms.name asc;

--- 2 ---

select ms.name, ms.birthdate, count(*)
from moviestar ms 
	join starsin si on ms.name = si.starname
	join movie m on si.movietitle = m.title
where  ms.name not like '%Jr.%'  and  m.incolor = 'Y'
group by ms.name
order by ms.birthdate desc, ms.name ASC

----- 07.2020 - 2 -----

--- 1 ---

select ms.name, year(ms.birthdate) as year, (select count(distinct m2.studioname) 
                                             from movie m2 join starsin si2 on m2.title = si2.movietitle 
                                             where ms.name = si2.starname) as count
from moviestar ms 
	join starsin si on ms.name = si.starname
where ms.gender = 'F'
group by ms.name;
having count(*) <= 6

--- 2 ---

select ms.name, year(ms.birthdate) as year, count(distinct m.studioname)
from moviestar ms 
	left join starsin si on ms.name = si.starname
    left join movie m on si.movietitle = m.title
where ms.gender = 'F'
group by ms.name
having count(*) <= 6