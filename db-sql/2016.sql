
----- 07.2016 - 1 -----

SELECT t.name, title FROM movie m 
JOIN (SELECT name, `cert#`   
	  FROM movieexec  
	  WHERE `cert#` IN (SELECT `producerc#` 
					    FROM movie         
					    WHERE title = 'Pretty Woman')) t ON m.`producerc#` = t.`cert#`
						
----- 07.2016 - 2 -----

SELECT studioname, starname, COUNT(*)
FROM movie m JOIN starsin ON title = movietitle AND year = movieyear
WHERE studioname IS NOT NULL
GROUP BY studioname, starname 
HAVING COUNT(*) >= ALL (SELECT COUNT(*)
                        FROM movie, starsin 
                        WHERE title = movietitle AND year = movieyear AND studioname = m.studioname  
                        GROUP BY studioname, starname);