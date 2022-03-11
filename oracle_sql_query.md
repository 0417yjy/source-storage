# Oracle SQL 힌트
[출처](https://gurume.tistory.com/entry/%EC%98%A4%EB%9D%BC%ED%81%B4-%EC%9E%90%EC%A3%BC%EC%82%AC%EC%9A%A9%ED%95%98%EB%8A%94-%ED%9E%8C%ED%8A%B8%EB%AA%A9%EB%A1%9D-%EC%A0%95%EB%A6%AC%EC%B9%9C%EC%A0%88%ED%95%9C-sql-%ED%8A%9C%EB%8B%9D)
## 사용법
SELECT 바로 뒤에 `/*+ 힌트 */` 의 양식으로 사용. 여러 힌트를 사용할 때에는 공백으로 구분
```
SELECT
    /* + LEADING(A,B) USE_HASH(A,B) */
    *
FROM
    EXAMPLE A
    
    INNER JOIN EXAMPLE2 B
    ON 1=1
        AND B.PK = A.PK
```

## 최적화 목표
 * /*+ALL_LOWS */: 전체 처리속도 최적화
 * /*+FIRST_ROWS(N) */ : 최초 N건 응답속도 최적화

## 테이블 엑세스
 * /*+FULL */
 * /*+INDEX */
 * /*+INDEX_DESC */
 * /*+INDEX_FFS */: INDEX FAST FULL SCAN
 * /*+INDEX_SS */: INDEX SKIP SCAN

## 조인 순서
 * /*+ORDERED */: FROM절에 나열된 테이블 순서대로
 * /*+LEADING(A B C) */: A B C 순서대로
 * /*+SWAP_JOIN_INPUTS(A) */: 해시조인의 경우, BUILD INPUT를 명시적으로 선택

## 조인 방식
 * /*+USE_NL */ :NESTED LOOP 방식
 * /*+USE_MERGE */ 소트머지 조인
 * /*+USE_HASH */ 해시조인
 * /*+NL_SJ */: NL SEMI조인
 * /*+MERGE_SJ */: 소트머지 세미조인
 * /*+HASH_SJ */: 해시 세미조인

## WITH 절
 * /*+MATERIALIZE */: WITH문으로 정의한 집합을 물리적으로 생성하도록 유도 
    * WITH /*+ MATERIALIZE*/ T AS (SELECT ...)
 * /*+INLINE */: WITH문으로 정의한 집합을 물리적으로 생성하지않고 INLINE 처리하도록 유도
    * WITH /*+ INLINE*/ T AS (SELECT ...)

## 쿼리변환
 * /*+ MERGE */: 뷰 머징 유도
 * /*+NO_MERGE */: 뷰 머징 방지
 * /*+UNNEST */: 서브쿼리 UNNESTING 유도
 * /*+NO_UNNEST */: 서브쿼리 UNNESTING 방지
 * /*+PUSH_PRED */: 조인조건 PUSHDOWN 유도
 * /*+NO_PUSH_PRED */: 조인조건 PUSHDOWN 방지
 * /*+USE_CONCAT */: OR 또는 IN-LIST조건을 OR-EXPANSION으로 유도
 * /*+NO_EXPAND */: OR 또는 IN-LIST 조건에 대한 OR-EXPANSION방지
