
----- 09.2019 - 1 -----

SELECT ME.NAME, M.YEAR, COUNT(*) AS CNT
FROM MOVIEEXEC ME JOIN MOVIE M ON ME.CERT# = M.PRODUCERC#
GROUP BY ME.CERT#, ME.NAME, M.YEAR;

----- 09.2019 - 2 -----

SELECT * FROM moviestar m 
where m.birthdate = (select min(birthdate) from moviestar)

----- 07.2019 - 1 -----

SELECT S.NAME, COUNT(M.TITLE) as CNT 
FROM STUDIO S JOIN MOVIE M ON S.NAME = M.STUDIONAME 
GROUP BY S.NAME
HAVING COUNT(M.TITLE) < 2;

----- 07.2019 - 2 -----

SELECT ex.name 
FROM movieexec ex 
WHERE ex.networth = (select min(networth) from movieexec);