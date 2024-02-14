from django.core.mail import send_mail, EmailMessage
from django.conf import settings


def send_email_to_client():
    subject = "This Email is from Django Server"
    message = "This is Test message from Django server email."
    from_email = settings.EMAIL_HOST_USER
    recipient_list = []
    send_mail(subject, message, from_email, recipient_list)


def send_email_with_attachment(subject, message, recipient_list, file_path):
    mail = EmailMessage(subject=subject, body = message, from_email=settings.EMAIL_HOST_USER, to = recipient_list)
    mail.attach_file(file_path)
    mail.send()




# -------------------------------------------------------------- #

"""
from django.core.mail import EmailMessage
from django.template.loader import render_to_string
from django.utils.html import strip_tags


def send_email_with_attachment():
    subject = 'Subject of the email'
    to_email = ['recipient@example.com']

    # Create an EmailMessage object
    email = EmailMessage(subject, 'Body of the email', 'your_email@example.com', to_email)

    # Attach a file
    attachment_path = '/path/to/your/attachment.txt'
    email.attach_file(attachment_path)

    # Inline image
    inline_image_path = '/path/to/your/image.jpg'
    inline_image_cid = 'inline_image_cid'
    email.attach_file(inline_image_path, 'image/jpeg', inline_image_cid)

    # HTML content with the inline image
    html_content = render_to_string('email_template.html', {'inline_image_cid': inline_image_cid})
    email.attach_alternative(html_content, 'text/html')

    # Plain text content (optional)
    plain_text_content = strip_tags(html_content)
    email.attach_alternative(plain_text_content, 'text/plain')

    # Send the email
    email.send()
"""