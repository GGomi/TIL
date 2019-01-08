# JPA 연관관계

## 테이블에 맞춰서 객체를 모델링하는 경우
```java
Team team = new Team();
team.setName("TeamA");
em.persist(team);

Member member = new Member();
member.setName("Jeongmin");
member.setTeamId(team.getId());
em.persist(member);

// ... //
Member findMember = em.find(Member.class, member.getId());
Long teamId = findMember.getId();
em.find(Team.class, teamId);
tx.commit();
```
- 위처럼 Team 테이블에 맞춘 객체, Member 테이블에 맞춘 객체로 특정 id를 가지고 조회를 할 때 두번에 걸쳐서 가져옴 / 데이터 지향적 방법이다.(객체지향적인 방법이 아니다.)
- 객체를 테이블에 맞추어 데이터중심으로 모델링하면, 협력관계를 만들 수 없다.

## 연관관계 매핑 이론(JPA계의 포인터..)
### 1. 단방향 매핑
- 객체 간 참조할 수 있게 한 방향으로만 설계
- 일대다, 다대일
- Member Class에 Team 객체를 조인컬럼으로 생성
- Member에 Team 객체를 set하면 알아서 값이 할당된다.

```sql
select
        member0_.id as id1_0_0_,
        member0_.age as age2_0_0_,
        member0_.USERNAME as USERNAME3_0_0_,
        member0_.TEAM_ID as TEAM_ID4_0_0_,
        team1_.id as id1_1_1_,
        team1_.name as name2_1_1_ 
    from
        Member member0_ 
    left outer join
        Team team1_ 
            on member0_.TEAM_ID=team1_.id 
    where
        member0_.id=?
```
- Member와 Team클래스를 연관관계 후 find시 JPA에서 만들어 준 Query문

**지연로딩 설정 후 쿼리**

```sql
select
        member0_.id as id1_0_0_,
        member0_.age as age2_0_0_,
        member0_.USERNAME as USERNAME3_0_0_,
        member0_.TEAM_ID as TEAM_ID4_0_0_ 
    from
        Member member0_ 
    where
        member0_.id=?
```
- **@ManyToOne(fetch = FetchType.LAZY) / 지연로딩**
- **@ManyToOne(fetch = FetchType.EAGER) / default**
- 지연로딩 전에는 멤버 테이블과 팀 테이블을 Join을 통해서 두 테이블의 정보를 다 가져왔었는데 지연로딩 후에 멤버 테이블의 정보만 가져오는 걸 확인할 수 있다.
- 현업에서는 모두 LAZY로 해놓고, 필요한 부분만 차근차근 찾아서 변경

### 2. 양방향 매핑
// TODO


