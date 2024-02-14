from django.shortcuts import render, redirect
from django.http import HttpResponse
from .utils import send_email_to_client, send_email_with_attachment
from django.conf import settings
from .models import *
import random
# Create your views here.

def home(request):

    # Car.objects.create(car_name = f"nexon-{random.randint(0,1000)}")

    peoples = [
        {"name": "name1", "age": 15},
        {"name": "name2", "age": 26},
        {"name": "mame3", "age": 17},
        {"name": "name4", "age": 28},
        {"name": "name5", "age": 29},
    ]

    text = """Lorem ipsum dolor sit amet consectetur adipisicing elit. Officia voluptas nobis cupiditate culpa velit, modi laboriosam quae cum quod animi nesciunt a. Soluta sequi repudiandae voluptate dolorum animi voluptas deleniti, provident, beatae quod eum necessitatibus? Fuga eveniet obcaecati totam unde eos numquam, repellendus perspiciatis quis, rerum cum hic nisi. Perspiciatis?"""

    return render(request, "home/index.html", context={"peoples": peoples, "text": text})

def about(request):
    return render(request, "home/about.html")

def contact(request):
    return render(request, "home/contact.html")


def success_page(request):
    return HttpResponse("Seccuess page")

def send_email(request):
    send_email_to_client()
    return redirect("/")

def send_email_with_att(request):
    subject = "This Email is from Django Server with attachment"
    message = "This is Test message from Django server email. with attachment"
    recipient_list = []
    file_path = f"{settings.BASE_DIR}/main.xlsx"

    send_email_with_attachment(subject, message, recipient_list, file_path)
    return redirect("/")
