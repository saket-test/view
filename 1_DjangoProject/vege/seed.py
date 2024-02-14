"""Creates test data"""

from faker import Faker
import random
from .models import *
import time
from django.db.models import Sum

fake = Faker()


def seed_db(n=100) -> None:
    try:
        for _ in range(0, n):
            department_objs = Department.objects.all()
            random_index = random.randint(0, len(department_objs)-1)

            # Seed the random number generator with the current time
            random.seed(time.time())
            # Generate a unique random number
            unique_random_number = random.randint(100, 999)

            department = department_objs[random_index]
            student_id = f'STU-0{unique_random_number}'
            student_name =fake.name()
            student_email = fake.email()
            student_age = random.randint(18,30)
            student_address = fake.address()

            student_id_obj = StudentID.objects.create(student_id=student_id)

            student_obj = Student.objects.create(
                department = department,
                student_id = student_id_obj,
                student_name = student_name,
                student_email = student_email,
                student_age = student_age,
                student_address = student_address,
            )
    except Exception as e:
        print(e)

def create_subject_marks():
    try:
        student_objs = Student.objects.all()
        print("1")
        for student in student_objs:
            subjects = Subject.objects.all()
            print(subjects)
            print("2")
            for subject in subjects:
                SubjectMarks.objects.create(
                    subject =  subject,
                    student = student,
                    marks = random.randint(0,100),
                )

    except Exception as e:
        print(e)


def generate_report_card():
    ranks = Student.objects.annotate(marks = Sum("studentmarks__marks")).order_by("-marks", "-student_age")
  
    i = 1
    for rank in ranks:
        ReportCard.objects.create(
            student = rank,
            student_rank = i,
        )
        i += 1
