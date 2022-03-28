package com.qg.pojo;

public class Student {
    private int sid;
    private String name;
    private String gender;
    private int age;
    private String address;

    public Student() {
        super();
    }

    public Student(int sid, String name, String gender, int age, String birth, String address) {
        this.sid = sid;
        this.name = name;
        this.gender = gender;
        this.age = age;
        this.address = address;
    }

    public int getSid() {
        return sid;
    }

    public void setSid(int sid) {
        this.sid = sid;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    @Override
    public String toString() {
        return "Student{" +
                "sid=" + sid +
                ", name='" + name + '\'' +
                ", gender='" + gender + '\'' +
                ", age=" + age +
                ", address='" + address + '\'' +
                '}';
    }

}
