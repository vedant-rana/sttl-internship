USE YourDatabaseName;

SELECT 
    t.name AS TableName,
    c.name AS ColumnName,
    ty.name AS DataType,
    c.max_length AS MaxLength,
    c.is_nullable AS IsNullable,
    CASE
        WHEN pk.name IS NOT NULL THEN 'Yes'
        ELSE 'No'
    END AS IsPrimaryKey
FROM 
    sys.tables t
INNER JOIN 
    sys.columns c ON t.object_id = c.object_id
INNER JOIN 
    sys.types ty ON c.system_type_id = ty.system_type_id
LEFT JOIN 
    sys.indexes i ON t.object_id = i.object_id AND i.is_primary_key = 1
LEFT JOIN 
    sys.index_columns ic ON i.object_id = ic.object_id AND c.column_id = ic.column_id
LEFT JOIN 
    sys.key_constraints pk ON i.object_id = pk.parent_object_id AND ic.index_id = pk.unique_index_id
ORDER BY 
    t.name, c.column_id;
