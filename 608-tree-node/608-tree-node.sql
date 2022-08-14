SELECT id, CASE
                WHEN p_id IS NULL THEN 'Root'
                WHEN id NOT IN (SELECT p_id FROM Tree WHERE p_id IS NOT NULL) THEN 'Leaf'
                ELSE 'Inner'
                END AS type
FROM Tree
ORDER BY id;

# Reason for null check:  https://leetcode.com/problems/tree-node/discuss/1517271/NOT-IN-didn't-work-due-to-null/1500078