
----- 09.2015 - 1 -----

SELECT *
FROM (SELECT name, address
      FROM MovieStar
      WHERE gender = 'F'
      UNION
      SELECT name, address
      FROM Studio) T
WHERE T.address LIKE '%Sofia%'
ORDER BY T.address;

----- 09.2015 - 2 -----

SELECT name, address, AVG(length) AS avgLength
FROM Studio LEFT JOIN Movie ON name = studioName
WHERE NAME NOT IN (SELECT studioName
                   FROM Movie
                   WHERE inColor ='n'
                   GROUP BY studioName
                   HAVING COUNT(*) > 3)
GROUP BY name, address;

----- 07.2015 - 1 -----

SELECT starName
FROM StarsIn JOIN Movie ON movieTitle = title AND movieYear = year
WHERE starName NOT LIKE '%a' AND inColor = 'y'
INTERSECT
SELECT starName
FROM StarsIn JOIN Movie ON movieTitle = title AND movieYear = year
WHERE inColor = 'n';

----- 07.2015 - 2 -----

SELECT name, YEAR(birthdate), COUNT(DISTINCT studioName)
FROM MovieStar
	LEFT OUTER JOIN StarsIn ON name = starname
	LEFT JOIN Movie ON movieTitle = title AND movieYear = year
	GROUP BY name
	HAVING COUNT(title) <= 5
	