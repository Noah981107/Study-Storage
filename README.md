# Spring-Study
Weekly I learned about Toby Spring
```sql
ALTER TABLE [테이블 명] 

	ADD CONSTRAINT [제약조건 이름] FOREIGN KEY(컬럼 명)

		REFERENCES [부모테이블 명](PK 컬럼 명) [ON DELETE CASCADE / ON UPDATE CASCADE];
```

예시

'마이페이지'에서 댓글을 클릭하면, 해당 글로 이동한다.

내가 댓글을 작성한 글이 삭제되었을 때,  오류 화면을 보여주고 싶다.

어떻게 설계하실?

유저를 삭제할때에는 어케될까?

## 영속성에 관하여

[[10분 테코톡] 🧘‍♂️코즈의 JDBC, SQLMAPPER, ORM](https://www.youtube.com/watch?v=mezbxKGu68Y)

이거 보세연

---

/
