# Write your MySQL query statement below
SELECT id, visit_date, people
FROM Stadium s
WHERE people >= 100
  AND (
      -- current row + next two
      (EXISTS (SELECT 1 FROM Stadium s2 WHERE s2.id = s.id + 1 AND s2.people >= 100)
       AND EXISTS (SELECT 1 FROM Stadium s3 WHERE s3.id = s.id + 2 AND s3.people >= 100))
   OR -- current row + previous two
      (EXISTS (SELECT 1 FROM Stadium s2 WHERE s2.id = s.id - 1 AND s2.people >= 100)
       AND EXISTS (SELECT 1 FROM Stadium s3 WHERE s3.id = s.id - 2 AND s3.people >= 100))
   OR -- one before, one after
      (EXISTS (SELECT 1 FROM Stadium s2 WHERE s2.id = s.id - 1 AND s2.people >= 100)
       AND EXISTS (SELECT 1 FROM Stadium s3 WHERE s3.id = s.id + 1 AND s3.people >= 100))
  )
ORDER BY visit_date;